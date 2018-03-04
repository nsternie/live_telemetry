import matplotlib.pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
import pandas as pd
import sys

datafile = sys.argv[1]
pdf = PdfPages(data_file_name.rstrip('.csv')+'plots.pdf')
