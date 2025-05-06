from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from webdriver_manager.chrome import ChromeDriverManager
import time
import csv

# Set up Selenium WebDriver with auto-downloaded ChromeDriver
chrome_options = Options()
chrome_options.add_argument("--headless")  # Run in headless mode (no GUI)
chrome_options.add_argument("--disable-gpu")
chrome_options.add_argument("--no-sandbox")
chrome_options.add_argument("--window-size=1920,1080")

# Automatically install the correct ChromeDriver version
service = Service(ChromeDriverManager().install())
driver = webdriver.Chrome(service=service, options=chrome_options)

# Bark.com URL (replace with an allowed page)
URL = "https://www.bark.com/en/gb/services/"

# Open the URL
driver.get(URL)
time.sleep(3)  # Wait for JavaScript content to load

# Find service listings (modify selectors as needed)
services = driver.find_elements(By.CLASS_NAME, "service-card")  # Modify based on Bark.com's structure

# List to store scraped data
data = []

for service in services:
    try:
        title = service.find_element(By.TAG_NAME, "h2").text.strip()
    except:
        title = "N/A"

    try:
        link = service.find_element(By.TAG_NAME, "a").get_attribute("href")
    except:
        link = "N/A"

    try:
        description = service.find_element(By.TAG_NAME, "p").text.strip()
    except:
        description = "N/A"

    # Save data
    data.append([title, description, link])
    print(f"Scraped: {title} - {link}")

# Save data to CSV
with open("bark_services_selenium.csv", "w", newline="", encoding="utf-8") as file:
    writer = csv.writer(file)
    writer.writerow(["Title", "Description", "Link"])
    writer.writerows(data)

print("✅ Data saved to bark_services_selenium.csv")

# Close the Selenium driver
driver.quit()
