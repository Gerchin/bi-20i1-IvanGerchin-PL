import requests
import json

def write_json(data):
	with open('posts.json', 'w', encoding='utf-8') as file:
		json.dump(data, file, indent=2, ensure_ascii=False)

def request(offset):
	group_id = '120254617'
	url = 'https://api.vk.com/method/groups.getMembers'
	access_token = '13a07bced800f5b7cc4666fb74f38cbe3ac40fff5629d58f3993a83de8cb96ed8926baff47c161e27346d'

	r = requests.get(url,
		params={
		'v': '5.130',
		'group_id': '43391400',
		'access_token': access_token,
		'offset': str(offset),
		#'count': '0',
		'sort': 'id_asc'
		})

	return r

def main():
	all_users = []
	#write_json(request(66000).json())
	string_json = request(0).json()
	countUsers = string_json['response']['count']

	for i in range(0, countUsers, 1000):
		string_json = request(i).json()

		for k in string_json['response']['items']:
			all_users.append(k)
	print(all_users)

if __name__ == '__main__':
	main()