from PyQt5 import QtGui
from PyQt5.QtCore import Qt
import pyqtgraph as pg
import serial
import time
import os
import sys

run_name = input("Enter run name: ")
#command_log = open(run_name+".txt", "w+")

app = QtGui.QApplication([])
w = QtGui.QWidget()
w.setWindowTitle("Flight Computer Engineering GUI")
layout = QtGui.QGridLayout()
w.setLayout(layout)

ser = serial.Serial(port=sys.argv[1], baudrate=int(sys.argv[2]), timeout=0.1)

try:
    ser.open()
except:
    print("Could not open Serial Port")

def send(command_string):
    command_string = command_string + " \r"
    print("SENDING: "+command_string.rstrip('\n'))
    #command_log.write("%.3f,\tSENDING: " % time.clock()+command_string)
    if(ser.is_open):
        ser.write(command_string.encode('ascii'))

numfiles_button = QtGui.QPushButton('numfiles')
numfiles_button.clicked.connect((lambda: send("numfiles")))
layout.addWidget(numfiles_button, 1, 1)

newlog = QtGui.QPushButton('newlog')
newlog.clicked.connect((lambda: send("newlog")))
layout.addWidget(newlog, 2, 1)

closelog = QtGui.QPushButton("closelog")
closelog.clicked.connect((lambda: send("closelog")))
layout.addWidget(closelog, 3, 1)

test = QtGui.QPushButton("test")
test.clicked.connect((lambda: send("test")))
layout.addWidget(test, 4, 1)

nextpage = QtGui.QPushButton("nextpage")
nextpage.clicked.connect((lambda: send("nextpage")))
layout.addWidget(nextpage, 5, 1)

initfs = QtGui.QPushButton("initfs")
initfs.clicked.connect((lambda: send("initfs_yes_im_sure!")))
layout.addWidget(initfs, 6, 1)


if(0):
    p = w.palette()
    p.setColor(w.backgroundRole(), Qt.black)
    w.setPalette(p)

## Display the widget as a new window
w.show()

def loop():
    s = str(ser.readline().decode('ascii'))
    if(s):
        print(s)


timer = pg.QtCore.QTimer()
timer.timeout.connect(loop)
timer.start(10) # 100hz

## Start the Qt event loop
app.exec_()