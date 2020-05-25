var myBirthTime = new Date(1997, 1, 26, 10, 11);

function updateParagraph()
{
    var now = new Date();
    var seconds = (now.getTime() - myBirthTime.getTime()) / 1000;
    document.getElementById('birth-time').innerText = '生まれてから' + seconds + '秒経過。';
}

setInterval(updateParagraph, 50);
