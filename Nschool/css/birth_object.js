var birth = {
    myBirthTime: new Date(1997, 1, 26, 10, 11),
    updateParagraph: function()
    {
        var now = new Date();
        var seconds = (now.getTime() - birth.myBirthTime.getTime()) / 1000;
        document.getElementById('mybirth-time').innerText = seconds + ' seconds have passed since I was born.';
    }
    // SetInterval: setInterval(birth.updateParagraph, 50),
};

setInterval(birth.updateParagraph, 50)

var header = document.getElementById('header');
var degree = 0;
function rotateHeader()
{
    degree = degree + 6;
    degree = degree % 360;
    if ((0 <= degree && degree < 90) || (270 <= degree && degree < 360))
        header.className = 'face';
    else
        header.className = 'back';
    header.style.transform = 'rotateX(' + degree + 'deg)';
}

setInterval(rotateHeader, 25);