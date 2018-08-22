#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/if_ether.h>
#include <linux/sockios.h>
 
 
 
 
int getmac(char *mac) {
 
    char *device = "eth0"; //eth0是网卡设备名
    unsigned char macaddr[ETH_ALEN]; //ETH_ALEN（6）是MAC地址长度
    struct ifreq req;
    int err,i;
    int s;
 
 
    s=socket(AF_INET, SOCK_DGRAM,0); //internet协议族的数据报类型套接口
    strcpy(req.ifr_name, device); //将设备名作为输入参数传入
    err=ioctl(s, SIOCGIFHWADDR, &req); //执行取MAC地址操作
    close(s);
    if(err != -1) { 
        memcpy(macaddr, req.ifr_hwaddr.sa_data, ETH_ALEN); //取输出的MAC地址
        for(i = 0; i < ETH_ALEN; i++) {
            sprintf(mac, "%s%02x",mac, macaddr[i]&0xff);
            if(i != ETH_ALEN - 1) {
                sprintf(mac, "%s:", mac);
            }
        }
 
    } else {
        return -1;
    }
    return 0;
}
 
int net_util_get_ipaddr(char *dev,  char* ipaddr)
{
    struct ifreq ifr;
    int fd = 0;
    int ret = -1;
    struct sockaddr_in *pAddr;
    char net_dev[6] = {0};
    strcpy (net_dev, dev);
 
    if(NULL == ipaddr)
    {
        printf("illegal call function SetGeneralIP!\n");
        return -1;
    }
 
    if ((fd = socket(AF_INET,SOCK_DGRAM,0)) < 0)
    {
        printf("open socket failed\n");
        return -1;
    }
 
    memset(&ifr,0,sizeof(ifr));
    strcpy(ifr.ifr_name, net_dev);
 
    if (ioctl(fd, SIOCGIFADDR, &ifr) < 0)
    {
        //printf("SIOCGIFADDR socket failed %s ", strerror( errno ));
        close(fd);
        return -1;
    }
 
    pAddr = (struct sockaddr_in *)&(ifr.ifr_addr);
 
    strcpy(ipaddr, inet_ntoa(pAddr->sin_addr));
 
    if(0 == strlen(ipaddr))
    {
        printf( "ipaddr = [%s] len = 0\n", ipaddr);
        ret = -1;
    }
    else
    {	
        ret = 0;
        //printf( "ipaddr = [%s]\n", ipaddr);
    }
    close(fd);
 
    return ret;
}
 
int Get_Local_Ipv4netmask(char *Netmask, const char*dev)
{
    FILE *f;
    char aaa[11][100];
    char interface[10];
    char dest[10];
    char gateway[10];
    char netmask[10];
    int i;
    int result;
    int sss;
    char output[16];
 
    memset(output, 0, 16);
 
    if ((f = fopen("/proc/net/route", "r")) != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s \n", interface, dest,
                    gateway, aaa[3], aaa[4], aaa[5], aaa[6], netmask, aaa[8],
                    aaa[9], aaa[10]) != EOF)
        {
 
            result = 0;
            for (i = 0; i < 8; i++)
            {
                if (gateway[i] == 48)
                    result++;
            }
            if ((result == 8) && !strcmp(interface, dev))
            {
                printf("interface %s\n", interface);
                for (i = 8; i > 0; i = i - 2)
                {
                    sss = 0;
                    if (netmask[i - 2] >= 65)
                        sss = (netmask[i - 2] - 55) * 16;
                    else
                        sss = (netmask[i - 2] - 48) * 16;
                    if (netmask[i - 1] >= 65)
                        sss = sss + netmask[i - 1] - 55;
                    else
                        sss = sss + netmask[i - 1] - 48;
                    if (i > 2)
                    {
                        //printf("%d.",sss);
                        sprintf(output + strlen(output), "%d.", sss);
                    }
                    else
                    {
                        //printf("%d\n",sss);
                        sprintf(output + strlen(output), "%d", sss);
                        //printf("result:%s\n",output);
                        memcpy(Netmask, output, 16);
                        fclose(f);
                        return 0;
                    }
                }
            }
        }
        fclose(f);
    }
    else
    {
        return -1;
    }
    return -1;
}
 
 
int Get_Local_Ipv4gateway(char *Gateway, const char*dev)
{
    FILE *f;
    char aaa[11][100];
    char interface[10];
    char dest[10];
    char gateway[10];
    char netmask[10];
    int i;
    int result;
    int sss;
    char output[16];
 
    memset(output, 0, 16);
 
    if ((f = fopen("/proc/net/route", "r")) != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s \n", interface, dest,
                    gateway, aaa[3], aaa[4], aaa[5], aaa[6], netmask, aaa[8],
                    aaa[9], aaa[10]) != EOF)
        {
 
            result = 0;
            for (i = 0; i < 8; i++)
            {
                if (dest[i] == 48)
                    result++;
            }
            if ((result == 8) && !strcmp(interface, dev))
            {
                printf("interface %s\n", interface);
                for (i = 8; i > 0; i = i - 2)
                {
                    sss = 0;
                    if (gateway[i - 2] >= 65)
                        sss = (gateway[i - 2] - 55) * 16;
                    else
                        sss = (gateway[i - 2] - 48) * 16;
                    if (gateway[i - 1] >= 65)
                        sss = sss + gateway[i - 1] - 55;
                    else
                        sss = sss + gateway[i - 1] - 48;
                    if (i > 2)
                    {
                        //printf("%d.",sss);
                        sprintf(output + strlen(output), "%d.", sss);
                    }
                    else
                    {
                        //printf("%d\n",sss);
                        sprintf(output + strlen(output), "%d", sss);
                        //printf("result:%s\n",output);
                        memcpy(Gateway, output, 16);
                        fclose(f);
                        return 0;
                    }
                }
            }
        }
        fclose(f);
    }
    else
    {
        return -1;
    }
    return -1;
}
 
 
 
 
 
int main(void) 
{
 
    char wired_ip[20] = {0};
    char wiredless_ip[20] = {0};
    char netmask[20] = {0};
    char gateway[20] = {0};
    char mac[20] = {0};
    int ret;
 
    ret = getmac(mac);
    if (ret != 0) {
        printf("get mac fail\n");	
    } else {
        printf("mac=%s\n", mac);	
    }
 
    ret = net_util_get_ipaddr("eth0", wired_ip);
    if (ret != 0) {
        printf("get wire ip fail\n");	
    } else {
        printf("ip=%s\n", wired_ip);	
    }
    /*
       ret = net_util_get_ipaddr("wlan0", wiredless_ip);
       if (ret != 0) {
       printf("get wireless ip fail\n");	
       } else {
       printf("ip=%s\n", wiredless_ip);	
       }
       */
 
    ret = Get_Local_Ipv4netmask(netmask, "eth0");
    if (ret != 0) {
        printf("get netmask fail\n");
    } else {
        printf("netmask=%s\n", netmask);
    }
 
    ret = Get_Local_Ipv4gateway(gateway, "eth0");
    if (ret != 0) {
        printf("get gateway fail\n");
    } else {
        printf("gateway=%s\n", gateway);
    }	
 
    return 0;
}
