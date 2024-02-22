import pytube
a = input("Video URL: ")
fetch = pytube.YouTube(a)
filter = fetch.streams.filter(progressive=True, file_extension='mp4')
filter.get_highest_resolution().download()
print('Downloading finished..')
exit = input()