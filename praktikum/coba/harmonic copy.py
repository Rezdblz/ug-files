import numpy as np
import matplotlib.pyplot as plt


sampling_rate = 1000    
duration = 2            
t = np.linspace(0, duration, int(sampling_rate * duration), endpoint=False)

N = 1.0  

frequencies = [N/2, 3*N/2, 5*N/2, 7*N/2, 9*N/2]
amplitude = 1 
phase = 0      

signal = np.zeros_like(t)
for freq in frequencies:
    signal += amplitude * np.sin(2 * np.pi * freq * t + phase)


plt.figure(figsize=(10, 4))
plt.plot(t, signal, label="signal harmonic terkombinasi")
plt.xlabel("waktu (s)")
plt.ylabel("Amplitudo")
plt.title("Simulasi harmonic")
plt.legend()
plt.grid(True)
plt.show()
