

import numpy as np
import matplotlib.pyplot as plt
# Parameters for the harmonic signal
frequency = 0.5         # Frequency of the signal in Hz
sampling_rate = 1000   # Sampling rate in samples per second
duration = 2           # Duration of the signal in seconds
amplitude = 1          # Amplitude of the signal
phase = 0              # Phase shift in radians

# Generate the time array
t = np.linspace(0, duration, int(sampling_rate * duration), endpoint=False)

# Generate the harmonic signal
signal = amplitude * np.sin(2 * np.pi * frequency * t + phase)

# Plot the harmonic signal
plt.figure(figsize=(10, 4))
plt.plot(t, signal, label=f'{frequency} Hz Sine Wave')
plt.xlabel("Time (s)")
plt.ylabel("Amplitude")
plt.title("Simulated Harmonic Signal")
plt.legend()
plt.grid(True)
plt.show()