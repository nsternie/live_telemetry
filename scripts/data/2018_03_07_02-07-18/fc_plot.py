import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
import pandas as pd
import sys

df = pd.read_csv(sys.argv[1])
pdf = PdfPages(sys.argv[1].rstrip('.csv')+'_plots.pdf')

##for col in df:
##    data = df[col]
##    plt.figure(0)
##    try:
##        plt.plot(data, label=data.name)
##    except:
##        pass
##plt.figure(0)
##plt.title("ALL DATA")
##plt.legend()
##plt.savefig(pdf, format='pdf')


time = df["time"].tolist()

gyro = [0]*3
gyro[0] = df["gyro_x"].tolist()
gyro[1] = df["gyro_y"].tolist()
gyro[2] = df["gyro_z"].tolist()

plt.figure(1)
plt.plot(time, gyro[0], label='x')
plt.plot(time, gyro[1], label='y')
plt.plot(time, gyro[2], label='z')
plt.title("Gyro Data")
plt.legend()
plt.savefig(pdf, format='pdf')

accel = [0]*3
accel[0] = df["accel_x"].tolist()
accel[1] = df["accel_y"].tolist()
accel[2] = df["accel_z"].tolist()

plt.figure(2)
plt.plot(time, accel[0], label='x')
plt.plot(time, accel[1], label='y')
plt.plot(time, accel[2], label='z')
plt.title("Accel Data")
plt.legend()
plt.savefig(pdf, format='pdf')

barodata = df["barodata"]
plt.figure(3)
plt.plot(time, barodata)
plt.title("Barometer Data")
plt.savefig(pdf, format='pdf')

##plot_num = 3
##for col in df:
##    data = df[col]
##    # Column data
##    plt.figure(plot_num)
##    plot_num = plot_num + 1
##    plt.plot(data)
##    plt.title(data.name)


##for n in range(3, plot_num):
##    plt.figure(n)
##    plt.savefig(pdf, format='pdf')


pdf.close()
