import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Load the dataset
data = pd.read_csv('/Users/kareemaayman/Downloads/Weather Dataset.csv')  # Replace with your actual file path or URL

# Clean and preprocess data (handle missing values, duplicates, etc.)
# Example: data.dropna(inplace=True)

# Plot temperature over time
plt.plot(data['Formatted Date'], data['Temperature (C)'])
plt.xlabel('Date')
plt.ylabel('Temperature (C)')
plt.title('Temperature Over Time')
plt.show()

# Create a histogram of temperature distribution
plt.hist(data['Temperature (C)'])
plt.xlabel('Temperature (C)')
plt.ylabel('Frequency')
plt.title('Temperature Distribution')
plt.show()

# Scatter plot of temperature vs. humidity
plt.scatter(data['Temperature (C)'], data['Humidity'])
plt.xlabel('Temperature (C)')
plt.ylabel('Humidity')
plt.title('Temperature vs. Humidity')
plt.show()

# Generate a correlation heatmap
# Select only numeric columns for correlation calculation
numeric_data = data.select_dtypes(include=['number']) 
correlation_matrix = numeric_data.corr()
sns.heatmap(correlation_matrix, annot=True, cmap='coolwarm')
plt.title('Correlation Heatmap')
plt.show()