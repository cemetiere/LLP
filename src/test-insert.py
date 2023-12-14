import subprocess
import time
import pandas as pd
import matplotlib.pyplot as plt

num_runs = 10

execution_times = []

for _ in range(num_runs):
    # Run the compiled C program and measure execution time
    start_time = time.time()
    subprocess.call("/mnt/c/Users/Андрей/Desktop/Study/LLP/build/test", shell=True)  
    end_time = time.time()
    
    execution_time_ms = (end_time - start_time) * 1000
    
    execution_times.append(execution_time_ms)


# Create a Pandas DataFrame
df = pd.DataFrame({'Run': range(1, num_runs + 1), 'Execution Time (ms)': execution_times})

# Plot the execution times
plt.figure(figsize=(10, 6))
plt.plot(df['Run'], df['Execution Time (ms)'], marker='o')
plt.title('C Program Execution Times')
plt.xlabel('Run')
plt.ylabel('Execution Time (ms)')
plt.grid(True)

# Show the plot
plt.show()