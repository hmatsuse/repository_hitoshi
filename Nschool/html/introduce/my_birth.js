var myBirthTime = new Date(1997, 1, 26, 10, 11);

function updateParagraph()
{
    var now = new Date();
    var seconds = (now.getTime() - myBirthTime.getTime()) / 1000;
    document.getElementById('mybirth-time').innerText = seconds + ' seconds have passed since I was born.';
}

setInterval(updateParagraph, 50);
