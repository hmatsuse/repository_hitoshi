#include "get_next_line.h"
// #include "get_next_line_bonus.h"
#include<stdio.h>
#include<string.h>
#include<fcntl.h>


// gcc -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c main.c

// gcc -D BUFFER_SIZE=1024 get_next_line_bonus.c get_next_line_utils_bonus.c main.c

int main(void)
{
	int			fd[5];
	char		*line = NULL;
	int 		rc;
	// time_t		start, end;

	// fd = エラー
	// fd[0] = open("only.txt", O_RDONLY);
	// printf("%d\n", fd[0]);
	// close(fd[0]);
	// printf("エラー処理　%d : %s\n", get_next_line(-2, &line), line);
	//free(line);
	// printf("エラー処理　%d : %s\n", get_next_line(1000, &line), line);

	// puts("------------------普通--------------------");
	// // 普通

	// fd[0] = open("test", O_RDONLY);
	// // start = clock();
	// while ((rc = get_next_line(fd[0], &line)) > 0)
	// {
	// 	printf("%d : %s\n", rc, line);
	// }
	// // end = clock();
	// printf("%d : %s\n", rc, line);
	// // printf("time : %.6f\n", (double)(end - start) / CLOCKS_PER_SEC);

	puts("------------------ボーナス-----------------------");
	// bonus用のたくさん来るやつ

	fd[1] = open("normal.txt", O_RDONLY);
	fd[2] = open("fewchar_perline.txt", O_RDONLY);
	rc = get_next_line(fd[1], &line);
	printf("%d : %s\n", rc, line);
	rc = get_next_line(fd[2], &line);
	printf("%d : %s\n", rc, line);
	rc = get_next_line(fd[1], &line);
	printf("%d : %s\n", rc, line);
	rc = get_next_line(fd[2], &line);
	printf("%d : %s\n", rc, line);
	rc = get_next_line(fd[1], &line);
	printf("%d : %s\n", rc, line);
	rc = get_next_line(fd[2], &line);
	printf("%d : %s\n", rc, line);

	// puts("------------------空のファイル-------------------------");
	// // empty
	// fd[3] = open("empty.txt", O_RDONLY);
	// rc = get_next_line(fd[3], &line);
	// printf("%d : %s\n", rc, line);

	// puts("------------------1行---------------------------");
	// // 1行
	// fd[4] = open("oneline.txt", O_RDONLY);
	// rc = get_next_line(fd[4], &line);
	// printf("%d : %s\n", rc, line);

	// puts("------------------標準入力-------------------------");
	// // 標準入力
	// while ((rc = get_next_line(1, &line)) > 0)
	// {
	// 	printf("%d : %s\n", rc, line);
	// }
	// printf("%d : %s\n", rc, line);


	// //　メモリリーク確認

	// // int rc;
	// // char *line;
	// // int fd;

	// // fd = open("only.txt", O_RDONLY);
	// // while ((rc = get_next_line(fd, &line)) > 0)
	// // {
	// // 	free(line);
	// // }
	// // free(line);
	// // while (1);




	// return (0);
}
