
import matplotlib.pyplot as plt
import csv
import statistics
#import plotly

filename = input("Paste csv filename \n")
runs_per_test = input("Trials per test\n")

print(filename)
print(runs_per_test)

xvals = []
yvals = []
test = []
meds = []
std_devs = []

runs_per_test = 3

with open('/Users/iansquiers/Desktop/fakeData.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    line_count = 0
    for row in csv_reader:
        print(row)
        if line_count == 0:
            plt.xlabel(row[0])
            plt.ylabel(row[1])
            line_count += 1
        else:
            if len(test) == runs_per_test:
                xvals.append(row[0])
                yvals.append(statistics.mean(test))
                meds.append(statistics.median(test))
                std_devs.append(statistics.pstdev(test)) #plt.errorbar(x,y,std_devs, linestyle='None', marker='^')
                test = []

            test.append(float(row[1])) #add each run to the test
            line_count += 1

print(xvals)
print(yvals)
plt.errorbar(xvals, yvals, std_devs, linestyle='None', marker='^')
plt.show()










