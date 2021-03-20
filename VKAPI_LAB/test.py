import requests
import json

def write_json(data):
	with open('posts.json', 'w', encoding='utf-8') as file:
		json.dump(data, file, indent=2, ensure_ascii=False)

def request(offset):
	group_id = '120254617'
	url = 'https://api.vk.com/method/groups.getMembers'
	access_token = 'b7bca36405509eedc3346424def1266b792f1a2dc499569821d8e7fd85c6323bc3ba7b80fd8371eae7fdc'

	r = requests.get(url,
		params={
		'v': '5.130',
		'group_id': '154434845',
		'access_token': access_token,
		'offset': str(offset),
		#'count': '0',
		'sort': 'id_asc'
		})

	return r

def main():
	write_json(request(2000).json())

if __name__ == '__main__':
	main()
