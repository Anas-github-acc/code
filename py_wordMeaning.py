from urllib.request import urlopen
from bs4 import BeautifulSoup

def extract(url):
    page = urlopen(url)
    html_bytes = page.read()
    html = html_bytes.decode("utf-8")
    soup = BeautifulSoup(html, "html.parser")
    content = soup.find("div", {"class": "_bzA3f8_vqmJSIKsgOar"})
    content = content.findAll("li")
    value = ""
    for i in content:
        content = i.find("div", {"class": "ESah86zaufmd2_YPdZtq"}).find("p")
        value += "* "+content.text+"\n"
    return value

content = ""
with open("words.txt", "r") as f:
    for line in f:
        word = ""
        cont = ""
        for letter in line:
            word = word.lower()
            if letter == " ":
                cont += word+"\n"
                url=f"https://www.dictionary.com/browse/{word}"
                cont += extract(url)
                print(cont)
                content += cont+"\n"
                break
            else:
                word += letter
with open("wordMeaning.txt", "w") as f:
    f.write(content)