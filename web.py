# amazon web scraper using autoscraper

from autoscraper import AutoScraper

# Define the website URL and the search query term

url = 'https://www.amazon.com/s?k='
search_term = 'shirt'

# wanted list of items to be scraped and link of the image

wanted_list = ['shirt', ''] # empty string for the link


# Create the AutoScraper object

scraper = AutoScraper()

# Build the model

result = scraper.build(url+search_term, ['shirt'])

# Print the results

print(result)

# Save the model

scraper.save('amazon-search')

# Load the model

