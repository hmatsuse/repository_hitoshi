
var game = {
    startTime: null,
    displayArea: document.getElementById('display-area'),
    start: function()
    {
        game.startTime = Date.now();
        document.body.onkeydown = game.stop;
        console.log('スタートしました');
    },
    stop: function()
    {
        var currentTime = Date.now();
        var seconds = (currentTime - game.startTime) / 1000;
        
        if (seconds == 10.0)
           game.displayArea.innerText = 'おおおお～すご！ぴったり'　+ seconds + '秒でした！';
        else if (9.5 <= seconds && seconds <= 10.5)
            game.displayArea.innerText = seconds + '秒でした。すごい！';
        else
            game.displayArea.innerText = seconds + '秒でした。残念。';
        console.log('ストップしました');
    }
};


if (confirm('OKを押して10秒だと思ったら何かキーを押してください'))
    game.start()
