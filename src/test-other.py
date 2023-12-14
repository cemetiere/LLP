import subprocess
import time
import pandas as pd
import matplotlib.pyplot as plt
import os
num_runs = 100

execution_times = []

for i in range(num_runs):
    try:
        os.remove('C:\\Users\\moyak\\CLionProjects\\llp\\lab-1\\test.file')
    except OSError:
        pass

    start_time = time.time()
    subprocess.call(['C:\\Users\\moyak\\CLionProjects\\llp\\lab-1\\cmake-build-debug\\llp.exe', '1', str(i+1)], shell=True)  
    end_time = time.time()

    #subprocess.call(['C:\\Users\\moyak\\CLionProjects\\llp\\lab-1\\cmake-build-debug\\llp.exe', '4'], shell=True)  
    
    execution_time_ms = (end_time - start_time) * 1000
    
    execution_times.append(execution_time_ms)


df = pd.DataFrame({'Run': range(1, num_runs + 1), 'Execution Time (ms)': execution_times})

plt.figure(figsize=(10, 6))
plt.plot(df['Run'], df['Execution Time (ms)'], marker='o')
plt.title('C Program Execution Times')
plt.xlabel('Run')
plt.ylabel('Execution Time (ms)')
plt.grid(True)

plt.show()