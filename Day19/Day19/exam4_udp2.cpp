#include "stdafx.h"

void exam4() {
	const int BUF_SIZE = 1024;
	const int PORT = 13333;
	SOCKET s;
	sockaddr_in peer_this, peer_other;

	char szBuf[BUF_SIZE] = {};
	WSADATA wsa;

	puts("\nInit socket.....\n");

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		printf("failed WSAStartup %d\n", WSAGetLastError());
	}

	puts("Init socket.....success\n");

	if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
		printf("failed create socket %d\n", WSAGetLastError());
	}

	puts("create socket.....success\n");

	peer_this.sin_family = AF_INET;
	peer_this.sin_addr.S_un.S_addr = INADDR_ANY;
	peer_this.sin_port = htons(PORT);

	if (bind(s, (sockaddr*)&peer_this, sizeof(peer_this)) == SOCKET_ERROR) {
		printf("bind error %d", WSAGetLastError());
	}

	printf("bind success 220.83.195.124 %d\n", PORT);

	int recv_len, slen;
	srand(time(NULL));
	int _rnd = rand() % 100;


	while (1) {
		puts("wait data.....\n");
		fflush(stdout);
		memset(szBuf, 0x00, BUF_SIZE);
		slen = sizeof(peer_other);
		if ((recv_len = recvfrom(s, szBuf, BUF_SIZE, 0, (sockaddr*)&peer_other, &slen)) == SOCKET_ERROR) {
			printf("recvform failed %d\n", WSAGetLastError());
		}

		printf("remote info : %s, %d\n", inet_ntoa(peer_other.sin_addr), ntohs(peer_other.sin_port));
		printf("Data : %s\n", szBuf);

		cJSON *pRoot = cJSON_Parse(szBuf);

		if (!pRoot) {
			puts("parse error\n");
		}
		else {
			cJSON *pNum = cJSON_GetObjectItemCaseSensitive(pRoot, "num");
			if (pNum) {
				printf("your number is %d\n", pNum->valueint);
				char _szBuf[BUF_SIZE] = {};
				if (pNum->valueint < _rnd) {
					//puts("too small\n");
					strcpy_s(_szBuf, "too small");					
				}
				else if (pNum->valueint > _rnd) {
					//puts("TOO BIG\n");
					strcpy_s(_szBuf, "TOO BIG");
				}
				else {
					//printf("%d\n", _rnd);
					strcpy_s(_szBuf, "Great!! U A Winner!");
				}

				puts(_szBuf);
				puts("\n");

				sendto(s, _szBuf, strlen(_szBuf), 0, (sockaddr*)&peer_other, ntohd(peer_other.sin_port));
			}
			else {
				puts("Data Errer\n");
			}
		}
	}
}