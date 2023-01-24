/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:23:54 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/24 13:57:19 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	cmd[] = "/usr/bin/env";

	char	*argVec[] = {"env", NULL};
	char	*envVec[] = {NULL};
	printf("Start of execve %s\n", cmd);
	if (execve(cmd, argVec, envVec) == -1)
		perror("Could not execute execve");
	
	printf("Something went wrong.");
	return (0);
}

	// char	cmd[] = "/bin/ls";

	// char	*argVec[] = {"ls", "-l", "-a", NULL};
	// char	*envVec[] = {NULL};
	// printf("Start of execve %s\n", cmd);
	// if (execve(cmd, argVec, envVec) == -1)
	// 	perror("Could not execute execve");
	
	// printf("Something went wrong.");
	// return (0);
// execve -> arg + variable environment
// two way comm
	// int	p1[2];
	// int p2[2];

	// if (pipe(p1) == -1)
	// 	return (1);
	// if (pipe(p2) == -1)
	// 	return (1);
	// int pid = fork();
	// if (pid == -1)
	// 	return (2);
	// if (pid == 0)
	// {
	// 	close(p1[0]);
	// 	close(p2[1]);
	// 	int x;
	// 	if (read(p2[0], &x, sizeof(x)) == -1)
	// 		return (3);
	// 	x *= 4;
	// 	if (write(p1[1], &x, sizeof(x)) == -1)
	// 		return (4);
	// 	close(p1[1]);
	// 	close(p2[0]);
	// }
	// else
	// {
	// 	close(p1[1]);
	// 	close(p2[0]);
	// 	srand(time(NULL));
	// 	int y = rand() % 10;
	// 	if (write(p2[1], &y, sizeof(y)) == -1)
	// 		return (5);
	// 	if (read(p1[0], &y, sizeof(y)) == -1)
	// 		return (6);
	// 	printf("result is %d\n", y);
	// 	close(p1[0]);
	// 	close(p2[1]);
	// 	wait(NULL);
	// }
	// close(p1[0]);
	// close(p1[1]);
	// return (0);
// fifo
	// if (mkfifo("myfifo1", 0777) == -1) // read from wrote too by anybody
	// {
	// 	if (errno != EEXIST)
	// 	{
	// 		printf("here");
	// 		exit(1); 
	// 	}
	// }
	// printf("openning\n");
	// int fd = open("myfifo1", O_RDWR);
	// printf("open\n");
	// int	x = 97;
	// if (write(fd, &x, sizeof(x)) == -1)
	// 	exit(1);
	// printf("written\n");
	// close(fd);
	// printf("closed\n");

// pipes
	// int	fd[2];
	// int	id;
	
	// if (pipe(fd) == -1)
	// 	exit(EXIT_FAILURE);
	// id = fork();
	// if (id == 0)
	// {
	// 	close(fd[0]); // we dont need it here - we never read form fd[0]
	// 	int	x;
	// 	printf("input a number: ");
	// 	scanf("%d", &x);
	// 	if (write(fd[1], &x, sizeof(int)) == -1)
	// 	{
	// 		printf("an error occured while writing");
	// 		exit(1);
	// 	}
	// 	close(fd[1]); // to anybody on the other end the file has been closed cant write to it
	// }
	// else
	// {
	// 	close(fd[1]);
	// 	int y;
	// 	if (read(fd[0], &y, sizeof(int)) == -1)
	// 	{
	// 		printf("an error occured while reading");
	// 		exit(1);
	// 	}
	// 	y = y * 3;
	// 	close(fd[0]);
	// 	printf("got from child process: %d\n", y);
	// }

// multiple forks
	// int	id1 = fork();
	// int id2 = fork();
	// if (id1 == 0)
	// {
	// 	if (id2 == 0)
	// 		printf("we are in process y\n");
	// 	else
	// 		printf("we are in process x\n");
	// }
	// else
	// {
	// 	if (id2 == 0)
	// 		printf("we are in process z\n");
	// 	else
	// 		printf("we are in parent process\n");
		
	// }
	// while (wait(NULL) != -1 || errno != ECHILD) // we ahve 3 child processes 
	// 	printf("waited for a child to finish\n");

// process ID
	// int id = fork();
	// int	res;
	
	// if (id == 0)
	// 	usleep(1000000);
	// printf("current id: %d, parent id : %d\n", getpid(), getppid());
	// res = wait(NULL);
	// if (res == -1)
	// 	printf("no child to wait for\n");
	// else
	// 	printf("%d finsihed exec\n", res);

// wait fct
	// int id = fork();
	// int x;
	// int i = 0;
	
	// if (id == 0) // child process
	// {
	// 	x = 1;
	// }
	// else
	// {
	// 	x = 6;
	// }
	// wait(&id);
	// for (i = x; i < x + 5; i++)
	// {
	// 	printf("%d\n", i);
	// 	fflush(stdout);
	// }
	// return (0);
	
// fork function
	// if (id != 0) // in main process
	// 	x = fork();
	// printf("%d\n", x);
	// // if (id == 0)
	// // 	printf("Hello from child process: %d\n", id);
	// // else
	// // 	printf("Hello from parent process: %d\n", id);

// handling pipes
	// int	fd[2];

	// if (pipe(fd) == -1)
	// 	return (1);
	
	// int pid1 = fork();
	// if (pid1 < 0)
	// 	return (2);
	// if (pid1 == 0)
	// {
	// 	dup2(fd[1], STDOUT_FILENO);
	// 	close(fd[0]);
	// 	close(fd[1]);
	// 	execlp("ping", "ping", "-c", "5", "google.com", NULL);
	// }

	// int	pid2 = fork();
	// if (pid2 < 0)
	// 	return (3);
	// if (pid2 == 0)
	// {
	// 	dup2(fd[0], STDIN_FILENO);
	// 	close(fd[0]);
	// 	close(fd[1]);
	// 	execlp("grep", "grep", "round-trip", NULL);
	// }
	// close(fd[0]);
	// close(fd[1]);

	// waitpid(pid1, NULL, 0);
	// waitpid(pid2, NULL, 0);