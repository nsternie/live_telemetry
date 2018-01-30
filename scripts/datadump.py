import serial, sys, os, time

if(sys.argv[1] == "-h"):
    print("usage: "+sys.argv[0]+" COMXX baudrate [data folder override]")
    exit(0)

# Make data folder
cwd = os.getcwd()
if(len(sys.argv) == 4):
    datadir = cwd+"/data/"+sys.argv[3]
else:
    datadir = cwd+"/data/"+time.strftime("%Y_%m_%d_%H-%M-%S")
os.makedirs(datadir)

# Open Serial port
port = sys.argv[1]
baud = int(sys.argv[2])
try:
    ser = serial.Serial(port, baudrate=baud, timeout=0.25)
    print("Connected on "+port+" at "+str(baud)+"bps")
except:
    print("Could not open "+port)
    print("exiting...")
    exit(1)

# Download all binaries from the flight computer
ser.write(b'numfiles \r')                        # Check how many files there are
response = int(ser.readline())                  #
print("There are "+str(response)+" files to read...")
filelist = []
for filenum in range(response):                 
    print("Downloading file "+str(filenum)+"...")    
    filename = datadir+"/"+str(filenum)+".bin"       
    filelist.append(filename)                   
    binfile = open(filename, "wb")              # Open the binary
    readfile = True                
    command_string = "pfr "+str(filenum)+" \r"             
    ser.write(bytes(command_string, 'ascii'))        # send "Print file raw" to fc
    while(readfile):                            
       try:                                     
         page = ser.read(2048)                  # Read a page
         if(len(page) != 2048):
            readfile = False
         binfile.write(page)                    # Log to bin
       except SerialTimeoutException:       # Read pages until the fc stops sending them
         readfile = False                       # Then move on to the next file
       except:
         print("Serial error")                  # Oops
         exit(1) 
    binfile.close()                             # Close bin file

print("All files downloaded.")                 
ser.close()                                     
print(port+" closed.")


# Convert each binary into a csv
for binfile in filelist:
    print("Converting "+binfile+"...", end='')
    os.system("fc_bin2csv.exe "+str(binfile)+" > "+binfile.rstrip(".bin")+".csv")
    print(" done.")

print("done")