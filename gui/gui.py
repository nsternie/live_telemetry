import pandas as pd
from PyQt5 import QtGui
from PyQt5.QtCore import Qt
import pyqtgraph as pg
import serial
import serial.tools.list_ports
import struct
from bitstring import BitArray
from PlotDefinition import PlotDefinition
import ctypes

#TODO: Live Map - not impossible but will require at least a week of development time possibly

myappid = 'MASA.LiveTelem.GroundStationUI.1' # arbitrary string
ctypes.windll.shell32.SetCurrentProcessExplicitAppUserModelID(myappid)

#initialize run
run_name = input("Enter run name: ")
if len(run_name) == 0:
    run_name = 'test'

#logging file counter
file_counter = 0

#open serial
ports = [p.device for p in serial.tools.list_ports.comports()]
serial_log = open('data/'+ run_name + "_serial_log.txt", "w+")
ser = serial.Serial(baudrate=115200, timeout=0.5)

#connect to port
def connect():
    global ser, ports_box
    if ser.isOpen():
        ser.close()
    try:
        ser.port = str(ports_box.currentText())
        ser.open()
        ser.readline()
        top.statusBar().showMessage("Connection established on %s" % str(ports_box.currentText()))
    except:
        top.statusBar().showMessage("No connection")

#scan for com ports
def scan():
    global ports_box
    ports = [p.device for p in serial.tools.list_ports.comports()]
    ports_box.clear()
    ports_box.addItems(ports)

#command log
command_log = open('data/'+ run_name + "_command_log.txt", "w+")

#data buffer
data = []

#initialize data arrays (for testing only)
#eventually load data from web database into dataframe
cols = ['time','packetType', 'packetNumber', 'lat', 'long', 'baro', 'maxAlt', 'gyroZ', 'velAccel', 'accelZ', 'rssi']
database = pd.DataFrame(columns=cols)

#data log
data_log = open('data/'+ run_name + "_data_log_"+ str(file_counter) +".csv", "w+")

def write_line(file, cols):
    for h in cols:
        file.write(str(h) + ",")
    file.write("\n")

#write header to data_log
write_line(data_log, cols)

#global vars
launchAlt = 0;
alt = 0;
packetsLost = 0;
last_packet = 0;
machNumber = 0;

#initialize Qt
app = QtGui.QApplication([])

#timer
start_time = pg.ptime.time()

#top level
top = QtGui.QMainWindow()
w = QtGui.QWidget()
top.setCentralWidget(w)
top.setWindowTitle("MASA Live Data Dashboard")
app.setWindowIcon(QtGui.QIcon('logos/logo.png'))

# layout grid
layout = QtGui.QGridLayout()
w.setLayout(layout)

#load graph settings
graph_settings = pd.read_csv('graph_settings.csv')

#number of points to store given tick_rate and seconds_to_store
def tickCalc(tr, s):
    return int(s/(tr/1000))

#max number of datapoints to store/retrieve
tick_rate = 150 #in ms (calculated limit at about 35-40 ms)
seconds_to_store = graph_settings['seconds'].max() #save as much memory as possible (keep only what's needed)
data_range = tickCalc(tick_rate, seconds_to_store) #this isn't right and I don't know why

tabs = QtGui.QTabWidget()
map_widget = QtGui.QWidget()


#add area for tiled plots
plot_box = pg.GraphicsLayoutWidget()
plot_box.setBackground(None)
tabs.addTab(plot_box, "Telemetry")
tabs.addTab(map_widget, "Map")
layout.addWidget(tabs, 0, 1)

#add data area on side
data_fields = QtGui.QWidget()
data_layout = QtGui.QVBoxLayout()
layout.addWidget(data_fields, 0, 0)
data_fields.setLayout(data_layout)
data_layout.addStretch(1)

#connection box (add to connection_layout)
connection = QtGui.QGroupBox("Connection")
data_layout.addWidget(connection)
connection_layout = QtGui.QGridLayout()
connection.setLayout(connection_layout)

scanButton = QtGui.QPushButton("Scan")
scanButton.clicked.connect(scan)
connection_layout.addWidget(scanButton, 1, 0)
connectButton = QtGui.QPushButton("Connect")
connectButton.clicked.connect(connect)
connection_layout.addWidget(connectButton, 2, 0)
ports_box = QtGui.QComboBox()
connection_layout.addWidget(ports_box, 0, 0)

#comm stats box (add to comm_layout)
comm_stats = QtGui.QGroupBox("Comm Stats")
data_layout.addWidget(comm_stats)
comm_layout = QtGui.QGridLayout()
comm_stats.setLayout(comm_layout)

comm_layout.addWidget(QtGui.QLabel("Packets Lost: "), 0, 0)
comm_layout.addWidget(QtGui.QLabel("RSSI: "), 1, 0)
packetLossLabel = QtGui.QLabel("0")
rssiLabel = QtGui.QLabel()
comm_layout.addWidget(packetLossLabel, 0, 1)
comm_layout.addWidget(rssiLabel, 1, 1)

def reset_comms():
    global packetsLost
    top.statusBar().showMessage("Comm stats reset. Dropped packets: " + str(packetsLost))
    command_log.write("Comm stats reset. Dropped packets: " + str(packetsLost) + "\n")
    packetsLost = 0

resetCommStats = QtGui.QPushButton("Reset")
resetCommStats.clicked.connect(reset_comms)
comm_layout.addWidget(resetCommStats, 2, 0)

#flight stats box (add to flight_layout)
flight_stats = QtGui.QGroupBox("Flight Stats")
data_layout.addWidget(flight_stats)
flight_layout = QtGui.QGridLayout()
flight_stats.setLayout(flight_layout)

flight_layout.addWidget(QtGui.QLabel("Altitude: "), 0, 0)
flight_layout.addWidget(QtGui.QLabel("Max Altitude: "), 1, 0)
flight_layout.addWidget(QtGui.QLabel("Velocity: "), 2, 0)
flight_layout.addWidget(QtGui.QLabel("Mach Number: "), 3, 0)
flight_layout.addWidget(QtGui.QLabel("Acceleration: "), 4, 0)
flight_layout.addWidget(QtGui.QLabel("Roll: "), 5, 0)
baroLabel = QtGui.QLabel()
baroUnits = QtGui.QLabel("ft (ASL)")
maxAltLabel = QtGui.QLabel()
maxAltUnits = QtGui.QLabel("ft (ASL)")
velAccelLabel = QtGui.QLabel()
machLabel = QtGui.QLabel()
accelZLabel = QtGui.QLabel()
gyroZLabel = QtGui.QLabel()
flight_layout.addWidget(baroLabel, 0, 1)
flight_layout.addWidget(maxAltLabel, 1, 1)
flight_layout.addWidget(velAccelLabel, 2, 1)
flight_layout.addWidget(machLabel, 3 , 1)
flight_layout.addWidget(accelZLabel, 4, 1)
flight_layout.addWidget(gyroZLabel, 5, 1)
flight_layout.addWidget(baroUnits, 0, 2)
flight_layout.addWidget(maxAltUnits, 1, 2)
flight_layout.addWidget(QtGui.QLabel("ft/s"), 2, 2)
flight_layout.addWidget(QtGui.QLabel("ft/s^2"), 4, 2)
flight_layout.addWidget(QtGui.QLabel("deg/s"), 5, 2)

def zero_altitude():
    global alt, launchAlt
    launchAlt = alt
    baroUnits.setText("ft (AGL)")
    maxAltUnits.setText("ft (AGL)")
    top.statusBar().showMessage("Launch altitude set to " + str(launchAlt) + " ft")
    command_log.write("Launch altitude set to " + str(launchAlt) + " ft\n")


zeroAlt = QtGui.QPushButton("Zero Altitude")
zeroAlt.clicked.connect(zero_altitude)
flight_layout.addWidget(zeroAlt, 6, 0)

#location box (add to location_layout)
location_stats = QtGui.QGroupBox("Location")
data_layout.addWidget(location_stats)
location_layout = QtGui.QGridLayout()
location_stats.setLayout(location_layout)

location_layout.addWidget(QtGui.QLabel("Latitude: "), 0, 0)
location_layout.addWidget(QtGui.QLabel("Longitude: "), 1, 0)
latLabel = QtGui.QLabel()
longLabel = QtGui.QLabel()
location_layout.addWidget(latLabel, 0, 1)
location_layout.addWidget(longLabel, 1, 1)
location_layout.addWidget(QtGui.QLabel("deg"), 0, 2)
location_layout.addWidget(QtGui.QLabel("deg"), 1, 2)

#center data_field
data_layout.addStretch(1)

#command line
command_widget = QtGui.QWidget()
command_layout = QtGui.QGridLayout()
layout.addWidget(command_widget, 2, 1)
command_widget.setLayout(command_layout)

# Raw Command
def raw_command():
    if ser.isOpen():
        ser.write(raw_command_input.text().encode())
        top.statusBar().showMessage("Command: " + raw_command_input.text())
        command_log.write(raw_command_input.text()+'\n')
        raw_command_input.setText("")

raw_command_input = QtGui.QLineEdit()
raw_command_send = QtGui.QPushButton("Send Command")
raw_command_send.clicked.connect(raw_command)
raw_command_input.returnPressed.connect(raw_command)
command_layout.addWidget(raw_command_input, 0, 1)
command_layout.addWidget(raw_command_send, 0, 0)

mainMenu = top.menuBar()
mainMenu.setNativeMenuBar(True)
fileMenu = mainMenu.addMenu('&File')
dataMenu = mainMenu.addMenu('&Data')

#quit application function
#in case more shutdown actions are needed later
def exit():
    ser.close()
    serial_log.close()
    command_log.close()
    data_log.close()
    app.quit()

#quit application menu item
quit = QtGui.QAction("&Quit", fileMenu)
quit.setShortcut("Ctrl+Q")
quit.triggered.connect(exit)
fileMenu.addAction(quit)

#clear data function
def clear():
    global file_counter, data_log, cols
    data_log.close()
    database.drop(database.index, inplace=True)
    file_counter += 1
    top.statusBar().showMessage("Data cleared. Now writing to " + 'data/'+ run_name + "_data_log_"+ str(file_counter) + ".csv")
    command_log.write("Data cleared. Now writing to " + 'data/'+ run_name + "_data_log_"+ str(file_counter) + ".csv \n")
    data_log = open('data/'+ run_name + "_data_log_"+ str(file_counter) + ".csv", "w+")
    write_line(data_log, cols)

#clear data menu item
clear_data = QtGui.QAction("&Clear Data", dataMenu)
clear_data.setShortcut("Ctrl+D")
clear_data.triggered.connect(clear)
dataMenu.addAction(clear_data)

#list for easy iteration through plots
plots = []

#for each plot in parameters
for i in range(len(graph_settings.index)):
    #get parameters for plot
    row = graph_settings.ix[i]

    #plot location on screen
    subplot = (row['row'], row['col'])

    #initialize plot and add to list
    plots.append(PlotDefinition(subplot, title=row['title'], xlabel=row['xlabel'], ylabel=row['ylabel'], data_range=tickCalc(tick_rate, row['seconds'])))

    #set x data
    plots[i].setX(row['x'])

    #parse y data
    ys = row['y'].split(' | ')
    pens = row['pen'].split(' | ')
    aliases = row['alias'].split(' | ')
    params = zip(ys, pens, aliases)

    #push y data to plot
    for param in params:
        plots[i].addY(param)

    #make plot and push to window
    plots[i].makePlot(plot_box, show_legend=bool(row['legend']), show_grid=bool(row['grid']))

#update function runs on each tick
def update():
    global database, cols, ser, alt, packetsLost, last_packet, serial_log, data_log

    #get data
    try:
        if ser.isOpen():
            packet = ser.readline()
            serial_log.write(str(packet)+ "\n")
            # Unstuff the packet
            unstuffed = b''
            try:
                index = int(packet[0])
            except:
                return
            for n in range(1, len(packet)):
                temp = packet[n:n+1]
                if(n == index):
                    index = int(packet[n])+n
                    temp = b'\n'
                unstuffed = unstuffed + temp
            packet = unstuffed

            data = []
            data.append(pg.ptime.time() - start_time) #time

            byte_rep = packet[0:1]
            data.append(struct.unpack("<B", byte_rep)[0]) #packet type

            byte_rep = packet[1:3]
            data.append(struct.unpack("<h", byte_rep)[0]) #packet number

            byte_rep = packet[3:7]
            data.append(struct.unpack("<f", byte_rep)[0]) #lat

            byte_rep = packet[7:11]
            data.append(struct.unpack("<f", byte_rep)[0]) #long

            byte_rep = packet[11:13]
            data.append(struct.unpack("<h", byte_rep)[0]) #baro

            byte_rep = packet[13:15]
            data.append(struct.unpack("<h", byte_rep)[0]) #maxAlt

            byte_rep = packet[15:17]
            data.append(struct.unpack("<h", byte_rep)[0]) #gyroZ

            byte_rep = packet[17:19]
            data.append(struct.unpack("<h", byte_rep)[0]) #velAccel

            byte_rep = packet[19:22]
            accelZ = bin(struct.unpack('<I', byte_rep + b'\xFF')[0])[2:]
            data.append(BitArray(bin=accelZ[8]*8 + accelZ[8:]).int) #accelZ

            byte_rep = packet[22:23]
            data.append(struct.unpack("<B", byte_rep)[0]) #rssi

            #calculate packet loss
            if (last_packet != (data[2] - 1)) and (last_packet != -1) and (last_packet != (2^16 - 1)):
                packetsLost += data[2] - last_packet

            #write data to log
            write_line(data_log, data)

            #update gui
            last_packet = data[2]
            packetLossLabel.setText(str(packetsLost))
            rssiLabel.setText(str(data[10]))
            baroLabel.setText(str(data[5]-launchAlt))
            alt = data[5]
            data[5] -= launchAlt
            maxAltLabel.setText(str(data[6]-launchAlt))
            velAccelLabel.setText(str(data[8]))
            machLabel.setText('%.2f' % (data[8]/1116.44))
            accelZLabel.setText(str(data[9]))
            gyroZLabel.setText(str(data[7]))
            latLabel.setText('%.6f' % data[3])
            longLabel.setText('%.6f' % data[4])

            #update database
            database = database.append(pd.DataFrame([data],columns=cols))

            #slice off out of range data
            database = database.tail(data_range)

            #update plots with new data
            for p in plots:
                p.updatePlot(database)
    except:
        return

#display window
#using .showMaximized() instead of .show() until I can figure out sizing
top.showMaximized()

#timer and tick updates
timer = pg.QtCore.QTimer()
timer.timeout.connect(update)
timer.start(tick_rate)

#start application (Qt Loop Cycle)
app.exec_()
