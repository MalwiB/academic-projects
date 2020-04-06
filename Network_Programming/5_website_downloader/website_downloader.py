# -*- coding: utf-8 -*-
import urllib


def website_downloader(a_url):
	response = urllib.urlopen(a_url)
	code = response.getcode()
	if code is 404:
		print "File not found."
		return -1
	elif code is 200:
		print "URL was opened."
	data = response.read()
	print "Data downloaded."
	# w tym przypadku wystarczy wyszukac fraze w dokumencie
	# przy bardziej skomplikowanej operacji na dokumencie HTML mozna skorzystac z biblioteki Beautiful Soup
	text = 'content="text/html'
	if text not in data:
		print "Not HTML type."
		return -1
	site_identifier = "Ogłoszenia - Wydział Fizyki, Astronomii i Informatyki Stosowanej Uniwersytetu Jagiellońskiego"
	if site_identifier not in data:
		print "Not exactly site you are looking for, it may be internal server error."
		return -1
	print "Data checked, OK."
	# print data
	return 1


url = "http://www.fais.uj.edu.pl/dla-studentow/ogloszenia"
if website_downloader(url) is 1:
	print "Function website_downloader succeed."
else:
	print "Function website_downloader encountered error."
