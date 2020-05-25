'user strict';
const userNameInput = document.getElementById('user-name');
const assessmentButton = document.getElementById('assessment');
const resultDivided = document.getElementById('result-area');
const tweetDivided = document.getElementById('tweet-area');
const answers = [
    '{userName}さんのいいところは声です。{userName}さんの特徴的な声は皆を惹きつけ、心に残ります。',
    '{userName}さんのいいところはまなざしです。{userName}さんに見つめられた人は、気になって仕方がないでしょう。',
    '{userName}さんのいいところは情熱です。{userName}さんの情熱に周りの人は感化されます。',
    '{userName}さんのいいところは厳しさです。{userName}さんの厳しさがものごとをいつも成功に導きます。',
    '{userName}さんのいいところは知識です。博識な{userName}さんを多くの人が頼りにしています。',
    '{userName}さんのいいところはユニークさです。{userName}さんだけのその特徴が皆を楽しくさせます。',
    '{userName}さんのいいところは用心深さです。{userName}さんの洞察に、多くの人が助けられます。',
    '{userName}さんのいいところは見た目です。内側から溢れ出る{userName}さんの良さに皆が気を惹かれます。',
    '{userName}さんのいいところは決断力です。{userName}さんがする決断にいつも助けられる人がいます。',
    '{userName}さんのいいところは思いやりです。{userName}さんに気をかけてもらった多くの人が感謝しています。',
    '{userName}さんのいいところは感受性です。{userName}さんが感じたことに皆が共感し、わかりあうことができます。',
    '{userName}さんのいいところは節度です。強引すぎない{userName}さんの考えに皆が感謝しています。',
    '{userName}さんのいいところは好奇心です。新しいことに向かっていく{userName}さんの心構えが多くの人に魅力的に映ります。',
    '{userName}さんのいいところは気配りです。{userName}さんの配慮が多くの人を救っています。',
    '{userName}さんのいいところはその全てです。ありのままの{userName}さん自身がいいところなのです。',
    '{userName}さんのいいところは自制心です。やばいと思ったときにしっかりと衝動を抑えられる{userName}さんが皆から評価されています'
];

function removeAllChildren(element)
{
    while (element.firstChild)
        element.removeChild(element.firstChild);
};

userNameInput.onkeydown = event => {
    if (event.key === 'Enter')
        assessmentButton.onclick();
};

assessmentButton.onclick = function() {
    const userName = userNameInput.value;
    if (userName.length === 0)
        return;
    console.log(userName);
    console.log('ボタンが押されました');

    removeAllChildren(resultDivided);
    
    const header = document.createElement('h3');
    header.innerText = '診断結果';
    resultDivided.appendChild(header);
    
    const paragraph = document.createElement('p');
    const result = assessment(userName);
    paragraph.innerText = result;
    resultDivided.appendChild(paragraph);
    
    removeAllChildren(tweetDivided);
    const anchor = document.createElement('a');
    const hrefValue = 'https://twitter.com/intent/tweet?button_hashtag=' + encodeURIComponent('あなたの良いところ') + '&ref_src=twsrc%5Etfw';
    
    anchor.setAttribute('href', hrefValue);
    anchor.className = 'twitter-hashtag-button';
    anchor.setAttribute('data-text', result);
    anchor.innerText = 'Tweet #あなたの良いところ';
    
    tweetDivided.appendChild(anchor);
    
    const script = document.createElement('script');
    script.setAttribute('src', 'https://platform.twitter.com/widgets.js');
    tweetDivided.appendChild(script);
    // <script async src="https://platform.twitter.com/widgets.js" charset="utf-8"></script>
};
// ↓アロー関数
// assessmentButton.onclick = () => {
//     console.log('ボタンが押されました');
// }

function assessment(userName)
{
    let sumOfCharCode = 0;
    for (let i = 0; i < userName.length; i++)
    {
        sumOfCharCode = sumOfCharCode + userName.charCodeAt(i);
    }
    const index = sumOfCharCode % answers.length;
    let result = answers[index]
    result = result.replace(/\{userName\}/g, userName);
    return (result);
};

console.assert(
    assessment('太郎') ===
    '太郎さんのいいところは決断力です。太郎がする決断にいつも助けられる人がいます。',
    '診断結果の、文言の特定の部分を名前に置き換える処理が正しくありません。'
);
console.assert(
    assessment('太郎') === assessment('太郎'),
    '入力が同じ名前なら同じ診断結果を出力する処理が正しくありません。'
);

