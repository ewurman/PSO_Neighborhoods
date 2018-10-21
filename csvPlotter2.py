
import matplotlib.pyplot as plt
import csv
import statistics
import numpy as np

# filename = input("Paste csv filename \n")
# print(filename)
hold = []




def topos(x):
    return {
        0: 'Global',
        1: 'Ring',
        2: 'Von Neumann',
        3: 'Random'
    }.get(x, 'error') 

def bargraph(ind, space, yvals, width, topo, subp):
    ax = plt.subplot(subp)
    ax.bar(ind + space, yvals, width, label=topo, align='center', alpha=0.5, ecolor='black', capsize=10)
    ax.set_xticks(ind + width * 1.5)
    ax.set_xticklabels(('Global', 'Ring', 'Von Neumann', 'Random'))
    ax.set_ylim(0,200)

def plot1(file, subp, func):
    xvals = []
    yvals = []
    test = []
    std_devs = []

    runs_per_test = 20

    ind = np.arange(3)
    width = 0.15
    topo = 0
    with open(file) as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        line_count = 0
        topo = 0
        space = 0
        for row in csv_reader:
            #print(row)
            if line_count == 0:
                plt.xlabel(row[0])
                plt.ylabel(row[1])
                line_count += 1
            else:
                if len(row) == 2:
                    test.append(float(row[1])) #add each run to the test
                    if len(test) == runs_per_test:
                        xvals.append(row[0])
                        yvals.append(statistics.median(test))
                        std_devs.append(statistics.stdev(test)) #plt.errorbar(x,y,std_devs, linestyle='None', marker='^')
                        test = []
                else:
                    # bargraph(ind, space, yvals, width, topo, subp)
                    hold.append(yvals)
                    xvals = []
                    yvals = []
                    test = []
                    std_devs = []  
                    topo += 1
                    space+=width              
    print("\n\n\n",subp)
    plt.title(func)




# plot1('/Users/iansquiers/Desktop/NI/PSO_Neighborhoods/Ackley.csv', 221, 'Ackley')
# plot1('/Users/iansquiers/Desktop/NI/PSO_Neighborhoods/Rastrigin.csv', 222, 'Rastrigin')
# plot1('/Users/iansquiers/Desktop/NI/PSO_Neighborhoods/Rosenbrock.csv', 223, 'Rosenbrock')


# 16 plot

s = [[19.85805, 20.069699999999997, 20.02805, 20.71125],[122.37899999999999,138.10199999999998,94.72055,82.24115],[177.131,183.267,152.6995,179.423]]
t = [[19.82965, 20.02055, 19.9207,2.95809],[109.445, 124.6095,86.52600000000001,84.12530000000001],[97.7942,154.2245,82.38705, 107.4045]]
f = [[19.83365,19.94005,19.7747,0.116872],[73.1292,109.5195,63.67945, 138.2995],[88.00635,115.3835,135.3805, 124.0905]]

space = 0
ind = np.arange(4)
width = 0.25


bargraph(ind, space, s[0], width, 'Ackley', 221)
space += width
bargraph(ind, space, s[1], width, 'Rastrigin', 221)
space += width
bargraph(ind, space, s[2], width, 'Rosenbrock', 221)
space = 0
bargraph(ind, space, t[0], width, 'Ackley', 222)
space += width
bargraph(ind, space, t[1], width, 'Rastrigin', 222)
space += width
bargraph(ind, space, t[2], width, 'Rosenbrock', 222)
space = 0
bargraph(ind, space, f[0], width, 'Ackley', 223)
space += width
bargraph(ind, space, f[1], width, 'Rastrigin', 223)
space += width
bargraph(ind, space, f[2], width, 'Rosenbrock', 223)
space = 0



plt.legend(loc='lower right', bbox_to_anchor=(2.3,.5), ncol=2, framealpha = None, shadow=True)
plt.suptitle('Median Minimum Evaluation For Ras, Ack, & Ros at 1,000 iterations', fontsize=15)
plt.tight_layout()
plt.show()










