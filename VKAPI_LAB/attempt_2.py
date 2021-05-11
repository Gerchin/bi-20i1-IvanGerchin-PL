import requests
import json

class VKApi():
	def __init__(self):
		pass

	def request(self, offset):
		group_id = '154434845'
		url = 'https://api.vk.com/method/groups.getMembers'
		access_token = '13a07bced800f5b7cc4666fb74f38cbe3ac40fff5629d58f3993a83de8cb96ed8926baff47c161e27346d'

		r = requests.get(url,
			params={
			'v': '5.130',
			'group_id': group_id,
			'access_token': access_token,
			'offset': str(offset),
			#'count': '0',
			'sort': 'id_asc'
			})

		return r

	def pull_users(self):
		all_users = []
	
		string_json = super().request(0).json()

		countUsers = string_json['response']['count']

		for i in range(0, countUsers, 1000):
			string_json = super().request(i).json()

			for k in string_json['response']['items']:
				all_users.append(k)