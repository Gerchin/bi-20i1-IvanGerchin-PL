import requests
import json
import os
import time

def write_json(data):
	with open('posts.json', 'w', encoding='utf-8') as file:
		json.dump(data, file, indent=2, ensure_ascii=False)

def write_txt(count, users):
	file = open('temp/u%d.txt' % count, 'r+')
	file.writelines(users)
	#file.close()
	#file = open('temp/u%d.txt' % count, 'r')
	file.seek(0, os.SEEK_END)

	pos = file.tell() - 1

	while pos > 0 and file.read(1) != "\n":
		pos -= 1
		file.seek(pos, os.SEEK_SET)

	if pos > 0:
		file.seek(pos, os.SEEK_SET)
		file.truncate()

def request(group, offset):
	url = 'https://api.vk.com/method/groups.getMembers'
	access_token = '0239b22211077bd9188ca4b18315f63dc9381a3f6565e48fc8eaf4156a8a1b31bf581810e7a79d06c8137'

	r = requests.get(url,
		params={
		'v': '5.130',
		'group_id': group,
		'access_token': access_token,
		'offset': str(offset),
		#'count': '0',
		'sort': 'id_asc'
		})

	return r

def pull_users(group, count):
	all_users = []
	
	string_json = request(group, 0).json()

	countUsers = string_json['response']['count']

	for i in range(0, countUsers, 1000):
		string_json = request(group, i).json()

		for k in string_json['response']['items']:
			all_users.append(str(k) +  "\n")
		time.sleep(0.5)


	write_txt(count, all_users)

def main():
	groups_id = []
	counter = 0

	while True:
		print('Input ID of group:  ', end='')
		groups_id.append(str(input()))

		print('Continue? y/n')
		flag = input()

		os.system('cls')

		if flag.lower() == 'n' or flag.lower() == 'н':
			break

	for group in groups_id:
		pull_users(group, counter+1)
		counter += 1

if __name__ == '__main__':
	main()