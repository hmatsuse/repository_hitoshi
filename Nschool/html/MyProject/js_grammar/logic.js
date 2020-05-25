// var age = 20;
// var result = null;

// if (age >= 20)
//     result = '成年';
// else
//     result = '未成年';

// document.write(result);
// for (var i = 0; i <= 10; i++)
// {
//     document.write(i + ' ');
// }
// for (var i = 1; i <= 100; i++)
// {
//     if (i % 3 == 0 && i % 5 == 0)
//         document.write('FizzBuzz ');
//     else if (i % 5 == 0)
//         document.write('Buzz ');
//     else if (i % 3 == 0)
//         document.write('Fizz ');
//     else
//         document.write(i + ' ');
// }

// var a = []
// console.log(a)
// console.log(a.length)
// a.push('A','a')
// console.log(a)
// console.log(a.length)

// var a = ['あ', 'い', 'う', 'え', 'お', 'か', 'き', 'く', 'け', 'こ']

// for (var i = 0; i < a.length; i++)
// {
//     for (var s = 0; s < a.length; s++)
//         document.write(a[i] + a[s] + "<br>");
// }

function ft_write(i)
{
    document.write(i + i)
}

ft_write('Hello World')