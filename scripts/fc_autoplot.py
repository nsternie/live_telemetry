import matplotlib.pyplot as plt 
from matplotlib.backends.backend_pdf import PdfPages
import math
import pandas as pd
import re
import sys


data_file_name = sys.argv[1]
df = pd.read_csv(data_file_name)

pdf = PdfPages(data_file_name.rstrip('.csv')+'_plots.pdf')
    
g = [[0]]*3
a = g

time = df["time_ms"].tolist()
time = [x / 1000 for x in time]
g_id = df["gyro_id"].tolist()
g[0] = df["gx"].tolist()
g[1] = df["gy"].tolist()
g[2] = df["gz"].tolist()
a[0] = df["ax"].tolist()
a[1] = df["ay"].tolist()
a[2] = df["az"].tolist()
b = df["baro"].tolist()

## ALL GYROS ##
plt.figure(0)
plt.plot(time, g[0], label="Gyro X")
plt.plot(time, g[1], label="Gyro Y")
plt.plot(time, g[2], label="Gyro Z")
plt.title("GYROS")
plt.xlabel("Time (s)")
plt.ylabel("Rate (Unit)")
plt.legend()
plt.savefig(pdf, format='pdf')

## ALL ACCEL ##
plt.figure(1)
plt.plot(time, a[0], label="Accel X")
plt.plot(time, a[1], label="Accel Y")
plt.plot(time, a[2], label="Accel Z")
plt.title("ACCELS")
plt.xlabel("Time (s)")
plt.ylabel("Acceleration (Unit)")
plt.legend()
plt.savefig(pdf, format='pdf')


pdf.close()