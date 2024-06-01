import requests

url = "https://api.hix.ai/v1/sentiment"
headers = {
    "Content-Type": "application/json",
    "x-api-key": "YOUR_API_KEY"
}
data = {
    "input": "I love using the hix.ai API!",
    'model': 'fast'
}

response = requests.post(url, headers=headers, json=data)
sentiment = response.json()["sentiment"]
print(sentiment)
