import requests

url = "https://api.hix.ai/v1/sentiment"
headers = {
    "Content-Type": "application/json",
    "x-api-key": "9d9ca02af88048b6b2340491a718f463"
}
data = {
    "input": "I love using the hix.ai API!",
    'model': 'fast'
}

response = requests.post(url, headers=headers, json=data)
sentiment = response.json()["sentiment"]
print(sentiment)