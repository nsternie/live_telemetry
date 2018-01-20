import pandas as pd
from PyQt5 import QtGui
from PyQt5.QtCore import Qt
import pyqtgraph as pg
import time
import numpy as np
import pandas as pd
from PlotDefinition import PlotDefinition

#TODO: proper data stream (database?)
#TODO: add numerical fields (not just graphs) on the left side of screen
#TODO: mathematical operations on datasets (for calculating total thrust or pressure drop or what not)
#TODO: figure out window sizing (WTF WHY U NO WORK NO MATTER WHAT I TRY THE COLUMNS ARE DIFFERENT SIZES)

#window title
run_name = "MASA Live Data Dashboard"

#initialize Qt
app = QtGui.QApplication([])
#timer
start_time = pg.ptime.time()
#top level
top = QtGui.QMainWindow()
w = QtGui.QWidget()
top.setCentralWidget(w)
top.setWindowTitle(run_name)
app.setWindowIcon(QtGui.QIcon('logos/logo.png'))
# layout grid
layout = QtGui.QGridLayout()
w.setLayout(layout)

# Zero Indexes for the gui layout (row, column) (sternie's idea)
zr = 0
zc = 0

#load app settings (in the future will enable a settings menu)
app_settings = pd.read_csv("app_settings.csv")


#load graph settings
graph_settings = pd.read_csv(app_settings['graph_settings_path'][0])

#number of points to store given tick_rate and seconds_to_store
def tickCalc(tr, s):
    return int(s/(tr/1000))

#max number of datapoints to store/retrieve
tick_rate = app_settings['tick_rate'][0] #in ms (calculated limit at about 35-40 ms)
seconds_to_store = graph_settings['seconds'].max() #save as much memory as possible (keep only what's needed)
data_range = tickCalc(tick_rate, seconds_to_store) #this isn't right and I don't know why
#last_time = pg.ptime.time()

#initialize data arrays (for testing only)
#eventually load data from web database into dataframe
cols = ['time', 'cos', 'neg_cos', 'destruc']
database = pd.DataFrame(columns=cols)

#add area for tiled plots
plot_box = pg.GraphicsLayoutWidget()
layout.addWidget(plot_box, zr+0, zc+0)

#status = QtGui.statusBar(top)
mainMenu = top.menuBar()
mainMenu.setNativeMenuBar(True)
fileMenu = mainMenu.addMenu('&File')
dataMenu = mainMenu.addMenu('&Data')

#quit application function
#in case more shutdown actions are needed later
def exit():
    app.quit()

#quit application menu item
quit = QtGui.QAction("&Quit", fileMenu)
quit.setShortcut("Ctrl+Q")
quit.triggered.connect(exit)
fileMenu.addAction(quit)

#clear data function
def clear():
    database.drop(database.index, inplace=True)

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

#fake data stream in place of serial or some other type of read in
def fake_data():
    t = pg.ptime.time() - start_time
    y1 = np.cos(2 * np.pi * (t%500))
    y2 = -y1
    y3 = y1+y2
    return [t,y1,y2,y3]

#update function runs on each tick
def update():
    global database, cols, last_time

    #print(str((pg.ptime.time()-last_time)*1000-tick_rate) + " ms lag time this tick")
    #last_time = pg.ptime.time()

    #get data
    t,y1,y2,y3 = fake_data()

    #update database
    database = database.append(pd.DataFrame([[t,y1,y2,y3]],columns=cols))

    #slice off out of range data
    database = database.tail(data_range)

    #update plots with new data
    for p in plots:
        p.updatePlot(database)

#display window
#using .showMaximized() instead of .show() until I can figure out sizing
top.showMaximized()

#timer and tick updates
timer = pg.QtCore.QTimer()
timer.timeout.connect(update)
timer.start(tick_rate)

#start application (Qt Loop Cycle)
app.exec_()
