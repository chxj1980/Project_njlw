#ifndef __USER_INFO_MGN_H__
#define __USER_INFO_MGN_H__


/*----------------------------------------------*
 * ����ͷ�ļ�                                   *
 *----------------------------------------------*/
#include <sys/types.h>
#ifdef WIN32
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#endif

#include <vector>
#include <string>
#include <queue>
#include <algorithm>

#include "libsip.h"
#include "common/gblconfig_proc.inc"
#include "service/alarm_proc.inc"

using namespace std;

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif /* __cplusplus */

    /*----------------------------------------------*
     * �ⲿ����˵��                                 *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �ⲿ����ԭ��˵��                             *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �ڲ�����ԭ��˵��                             *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ȫ�ֱ���                                     *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ģ�鼶����                                   *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * ��������                                     *
     *----------------------------------------------*/

    /*----------------------------------------------*
     * �궨��                                       *
     *----------------------------------------------*/

//modified by chenyu 131126
    /*�û����ݿ��е�������Ϣ*/
//�ṹ�嶨����޸�
    typedef struct _user_cfg_t
    {
        unsigned int id;                            /* �û����� */
        int enable;                                 /* �Ƿ����� */
        string user_id;                             /* �û�ͳһ���id */
        string user_name;                           /* �û����� */
        string register_account;                    /* �û�ע���˻� */
        string register_password;                   /* �û�ע������ */
        unsigned int user_level;                    /* �û��ȼ�*/
        int user_permission;                        /* �û�Ȩ��*/
        string user_ip;                             /* �û�ip ��ַ*/
        string user_mac;                            /* �û�mac ��ַ*/
        //int reg_info_index;                                          /* ��Ӧ��sipЭ��ջע����*/
        //int auth_count;                                              /* ��֤����*/
        _user_cfg_t()
        {
            id = 0;
            enable = 0;
            user_id = "";
            user_name = "";
            register_account = "";
            register_password = "";
            user_level = 0;
            user_permission = 0;
            user_ip = "";
            user_mac = "";
        }
    } user_cfg_t;

    /* �û���Ϣ�ṹ�� */
    typedef struct _user_info_t
    {
        unsigned int user_index;                         /* �û����� */
        char user_id[MAX_ID_LEN + 4];                    /* �û�ͳһ���id */
        char user_name[MAX_32CHAR_STRING_LEN + 4];       /* �û����� */
        unsigned int user_level;                         /* �û��ȼ� */
        int access_method;                               /* ���뷽ʽ: 0:���꣬1:˽��Э�飬Ĭ��0 */
        int tcp_sock;                                    /* ˽��Э�����ʱ��Ķ�Ӧ��TCP Socket */
        int tcp_keep_alive_sock;                         /* TCP ����� Socket */
        char login_ip[MAX_IP_LEN];                       /* ��¼��ip��ַ*/
        int login_port;                                  /* ��¼�Ķ˿ں�*/
        int reg_status;                                  /* �û�ע��״̬: 0, δע�ᣬ1����ע�ᣬ2����¼��ɣ�3��ע�������� */
        int reg_info_index;                              /* ��������ʱ��:��Ӧ��SIPЭ��ջ��ע����Ϣ��Index, ˽��Э������ʱ��:��Ӧ��TCP�����е�Index */
        int auth_count;                                  /* ��֤����*/

        int alarm_info_send_flag;                        /* �澯��Ϣ���ͱ�ʶ */
        int tvwall_status_send_flag;                     /* ����ǽ״̬��Ϣ���ͱ�ʶ */

        char strRegServerEthName[MAX_IP_LEN];            /* ע��ķ�����IP��ַ�������� */
        char strRegServerIP[MAX_IP_LEN];                 /* ע��ķ�����IP��ַ */
        int iRegServerPort;                              /* ע��ķ������˿ں� */

        char strCallID[MAX_128CHAR_STRING_LEN + 4];      /* ע��ľ��callid,��ʶ�Ƿ���ˢ��ע�� */

        char strRegGapIP[MAX_IP_LEN];                    /* ע��Ķ�Ӧ����բ������IP��ַ */

        unsigned int  nResved1;                          /* ����1 */
        char   strResved2[MAX_32CHAR_STRING_LEN + 4];    /* ����2 */
    } user_info_t;

    typedef std::map <int, user_info_t*> User_Info_MAP;
    typedef std::map <int, user_info_t*>::iterator User_Info_Iterator;

    extern int AddDeviceIndexToDeviceIDVector(vector<string>& DeviceIDVector, string& DeviceID);
    extern int AddDeviceIndexToDeviceIndexVector(vector<unsigned int>& DeviceIndexVector, unsigned int DeviceIndex);
    extern int AddDeviceIndexToSortVector(vector<unsigned int>& allDeviceIndexVector, vector<unsigned int>& DeviceIndexVector, vector<unsigned int>& sortDeviceIndexVector);
    extern int AddLogicDeviceInfoToXMLItem(CPacket* pOutPacket, DOMElement* ListAccNode, char* device_id, DBOper* pUser_Srv_dboper);
    extern int AddUserIndexToUserIndexVector(vector<unsigned int>& UserIndexVector, unsigned int UserIndex);
    extern int AddUserRegInfo2DB(unsigned int uUserIndex, char* strLoginIP, int iLoginPort, DBOper* pUser_Reg_dboper);
    extern int CreateGBLogicDeviceCatalogResponseXMLHead(CPacket** pOutPacket, int query_count, int record_count, char* strSN, char* strDeviceID, DOMElement** ListAccNode);
    extern int debug_user_info_list_lock(const char* file, int line, const char* func);
    extern int debug_user_info_list_unlock(const char* file, int line, const char* func);
    extern int DeleteAllUserRegInfoFromDB(DBOper* pUser_Reg_dboper);
    extern int DeleteUserRegInfoFromDB(unsigned int uUserIndex, char* strLoginIP, int iLoginPort, DBOper* pUser_Reg_dboper);
    extern int FindRCUUserDevicePermConfig(unsigned int user_index, DBOper* pUser_Srv_dboper, vector<string>& DeviceIDVector);
    extern int FindRCUUserGroupDevicePermConfig(unsigned int user_index, DBOper* pUser_Srv_dboper, vector<string>& DeviceIDVector);
    extern int FindUserDevicePermConfig(unsigned int user_index, DBOper* pUser_Srv_dboper, vector<string>& DeviceIDVector);
    extern int FindUserGroupDevicePermConfig(unsigned int user_index, DBOper* pUser_Srv_dboper, vector<string>& DeviceIDVector);
    extern int free_user_reg_info_by_tcp_socket(int tcp_socket);
    extern int IsMyUser(char* user_id);
    extern int IsUserHasPermissionForDevice(unsigned int device_index, user_info_t* pUserInfo, DBOper* pDboper);
    extern int IsUserRegInfoHasChange(user_info_t* pUserInfo, char* pcLoginIP, int iLoginPort, int iRegInfoIndex);
    extern int is_user_tcp_socket_in_use(int tcp_socket);
    extern int NotifyOnlineUserToAllClientUser(user_info_t* pUserInfo, int event, DBOper* pdboper);
    extern int SendAlarmMsgMailToUserByUserIndex(unsigned int user_index, alarm_msg_t* pAlarmMsg, DBOper* pDBoper);
    extern int SendAllDeviceStatusToAllClientUser(vector<string>& DeviceIDVector, int status);
    extern int SendAllDeviceStatusToClientUser(user_info_t* pUserInfo, vector<string>& DeviceIDVector, int status);
    extern int SendDeviceStatusToAllClientUser(char* device_id, int status, DBOper* pDboper);
    extern int SendFaultMsgMailToUserByUserIndex(unsigned int user_index, fault_msg_t* pFaultMsg, DBOper* pDBoper);
    extern int SendMessageToExceptOnlineUser(user_info_t* pExceptUserInfo, char* msg, int msg_len);
    extern int SendMessageToOnlineUser(char* msg, int msg_len, int is_alarm);
    extern int SendMessageToOnlineUser2(unsigned int device_index, char* msg, int msg_len, int is_alarm, DBOper* pDboper);
    extern int SendMessageToOnlineUserByUserID(char* user_id, char* msg, int msg_len);
    extern int SendMessageToOnlineUserByUserIDForTVWallStatus(char* user_id, char* msg, int msg_len);
    extern int SendMessageToOnlineUserByUserIndex(unsigned int user_index, char* msg, int msg_len);
    extern int SendMessageToOnlineUserForTVWallStatus(char* msg, int msg_len);
    extern int SendRCUDeviceStatusToAllClientUser(char* device_id, int status, int AlarmPriority, int guard_type, char* Value, char* Unit);
    extern void ShowOnlineUser(int sock);
    extern int UpdateAllUserRegInfo2DB(int reg_status, DBOper* pUser_Srv_dboper);
    extern int UpdateUserRegInfo2DB(char* user_id, int reg_status, DBOper* pUser_Srv_dboper);
    extern int UpdateUserRegInfo2DB2(string strUserID, DBOper* pUser_Srv_dboper);
    extern int UserGetAllGBDeviceListAndSendCataLogToClient(user_info_t* pUserInfo, char* strDeviceID, char* strSN, DBOper* pUser_Srv_dboper);
    extern int UserGetAllGBDeviceListAndSendCataLogToClientForTCP(char* user_ip, int user_port, int user_sock, char* strDeviceID, char* strSN, DBOper* pUser_Srv_dboper);
    extern int UserGetAllGBDeviceListAndSendRCUCataLogToClientForTCP(char* user_ip, int user_port, int user_sock, char* strDeviceID, char* strSN, DBOper* pUser_Srv_dboper);
    extern int UserGetGBDeviceListAndSendCataLogToClient(user_info_t* pUserInfo, char* strDeviceID, char* strSN, DBOper* pUser_Srv_dboper);
    extern int UserGetGBDeviceListAndSendCataLogToClientForTCP(char* user_ip, int user_port, int user_sock, unsigned int user_index, char* strDeviceID, char* strSN, DBOper* pUser_Srv_dboper);
    extern int UserGetGBDeviceListAndSendRCUCataLogToClientForTCP(char* user_ip, int user_port, int user_sock, unsigned int user_index, char* strDeviceID, char* strSN, DBOper* pUser_Srv_dboper);
    extern int user_info_add(user_info_t* user_info);
    extern int user_info_find(char* user_id, char* user_ip, int user_port);
    extern void user_info_free(user_info_t* user_info);
    extern user_info_t* user_info_get(int pos);
    extern user_info_t* user_info_get_by_user_id(char* user_id);
    extern user_info_t* user_info_get_by_user_index(unsigned int user_index);
    extern user_info_t* user_info_get_by_user_index_and_ip(unsigned int user_index, char* login_ip, int login_port);
    extern user_info_t* user_info_get_by_user_info(char* user_id, char* login_ip, int login_port);
    extern user_info_t* user_info_get_by_user_ip_and_port(char* login_ip, int login_port);
    extern int user_info_init(user_info_t** user_info);
    extern void user_info_list_free();
    extern int user_info_list_init();
    extern int user_info_list_lock();
    extern int user_info_list_unlock();
    extern int user_info_remove(char* user_id, char* user_ip, int user_port);

#ifdef ENABLE_DEBUG_LOCK
#define USER_ROUTE_INFO_SMUTEX_LOCK(s) debug_user_route_info_lock(s, __FILE__, __LINE__, __func__)
#define USER_ROUTE_INFO_SMUTEX_UNLOCK(s) debug_user_route_info_unlock(s, __FILE__, __LINE__, __func__)
#define USER_INFO_SMUTEX_LOCK() debug_user_info_list_lock(__FILE__, __LINE__, __func__)
#define USER_INFO_SMUTEX_UNLOCK() debug_user_info_list_unlock(__FILE__, __LINE__, __func__)
#else
#define USER_ROUTE_INFO_SMUTEX_LOCK(s) user_route_info_lock(s)
#define USER_ROUTE_INFO_SMUTEX_UNLOCK(s) user_route_info_unlock(s)
#define USER_INFO_SMUTEX_LOCK() user_info_list_lock()
#define USER_INFO_SMUTEX_UNLOCK() user_info_list_unlock()
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __UDP_TL_H__ */