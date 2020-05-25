class Video:
    def __init__(self, video_id, title):
        """クラスをインスタンス化するときに呼び出されるメソッド"""
        self.video_id = video_id
        self.title = title
    
    def play(self):
        """動画を再生する"""
        self.start()
        print(f"Playing {self.title}")
        self.stop()
    
    def start(self):
        """動画の再生を開始する"""
        print(f"Start {self.video_id}")
    
    def stop(self):
        """動画の再生を止める"""
        print(f"Stop {self.video_id}")
# title = 'ARROW'
# Video = Video('45bh256h2', title)
mylists = [Video('hfue2hu3', 'LEO'), Video('fnu3413nj', 'HERO'), Video('lske134k3', 'ZERO')]
for video in mylists:
    video.play()
    print("~~~~~~~~~~~~~~~~~")

mylists = {'hv3h5v34' : 'GOAL' , 'duhv5v342h' : 'BREAKING' , 'h3v234hjj' : 'HANTING'}
for k, v in mylists.items():
    Video(k, v).play()
    print("~~~~~~~~~~~~~~~~~")

# Video.play()
