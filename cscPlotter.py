
import matplotlib.pyplot as plt
import csv
import statistics
import numpy as np

# filename = input("Paste csv filename \n")
# print(filename)



def topos(x):
    return {
        0: 'Global',
        1: 'Ring',
        2: 'Von Neumann',
        3: 'Random'
    }.get(x, 'error') 

def bargraph(ind, space, yvals, width, topo, subp):
    ax = plt.subplot(subp)
    ax.bar(ind + space, yvals, width, label=topos(topo), align='center', alpha=0.5, ecolor='black', capsize=10)
    ax.set_xticks(ind + width * 1.5)
    ax.set_xticklabels(('16', '30', '49'))
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
                    bargraph(ind, space, yvals, width, topo, subp)
                    print()
                    xvals = []
                    yvals = []
                    test = []
                    std_devs = []  
                    topo += 1
                    space+=width              
    print("\n\n\n",subp)
    plt.title(func)



plot1('/Users/iansquiers/Desktop/NI/PSO_Neighborhoods/Ackley.csv', 221, 'Ackley')
plot1('/Users/iansquiers/Desktop/NI/PSO_Neighborhoods/Rastrigin.csv', 222, 'Rastrigin')
plot1('/Users/iansquiers/Desktop/NI/PSO_Neighborhoods/Rosenbrock.csv', 223, 'Rosenbrock')
plt.legend(loc='lower right', bbox_to_anchor=(2.3,.5), ncol=2, framealpha = None, shadow=True)
plt.suptitle('Median Minimum Evaluation For Ras, Ack, & Ros at 1,000 iterations', fontsize=15)
plt.tight_layout()

plt.show()










