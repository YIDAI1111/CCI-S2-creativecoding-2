import requests
from bs4 import BeautifulSoup

page = requests.get("https://www.bilibili.com")
soup = BeautifulSoup(page.content, 'html.parser')

top_items = []

products = soup.select('div.info-box')
for elem in products:
    title = elem.select('div.info > p.title')[0].text
    review_label = elem.select('p.play')[0].text
    info = {
        "title": title.strip(),
        "review": review_label.strip()
    }
    top_items.append(info)

print(top_items)