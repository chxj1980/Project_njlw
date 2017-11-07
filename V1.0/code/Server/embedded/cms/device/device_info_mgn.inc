#ifndef __DEVICE_INFO_MGN_H__
#define __DEVICE_INFO_MGN_H__


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

#include "libsip.h"
#include "libxml/Packet.h"

#include "common/gbldef.inc"
#include "common/DBOper.h"
#include "common/gblconfig_proc.inc"

#include "user/user_info_mgn.inc"
#include "route/route_info_mgn.inc"

#include <vector>
#include <string>
#include <map>

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

//added by chenyu 131127
    /* ��׼�����豸cfg �ṹ�� */
    typedef struct _GBDevice_cfg_t
    {
        int id;                              /* �豸���� */
        string device_id;                    /* �豸ͳһ��� */
        int enable;                          /* �Ƿ����� */
        int device_type;                     /* �豸����(ǰ���������NVR������CMS��TSU) */
        string register_account;             /* ע���˺� */
        string register_password;            /* ע������ */

        string device_ip;                    /* �豸ip��ַ */
        int device_max_camera;               /* �豸��Ƶ����ͨ���� */
        int device_max_alarm;                /* �豸��������ͨ���� */
        string device_manufacturer;          /* �豸������ */
        string device_model;                 /* �豸�ͺ� */
        string device_firmware;              /* �豸�汾 */
        int link_type;                       /* ��������: 0:���¼���1��ͬ����Ĭ��0 */
        string cms_id;                       /* ����CMS ID */
        int trans_protocol;                  /* ���䷽ʽ: 0:UDP��1��TCP��Ĭ��0 */

        string login_ip;                     /* ��¼��ip��ַ*/
        int login_port;                      /* ��¼�Ķ˿ں�*/
        int reg_status;                      /* ע��״̬ */
        int reg_info_index;                  /* ��Ӧ��SIPЭ��ջ��ע����Ϣ��Index */
        int auth_count;                      /* ��֤ʧ�ܴ��� */
        _GBDevice_cfg_t()
        {
            id = 0;
            enable = 0;
            //device_type_t device_type;          /* �豸����(ǰ���������NVR������CMS��TSU) */
            register_account = "";
            register_password = "";
            device_ip = "";
            device_max_alarm = 0;
            device_manufacturer = "";
            device_model = "";
            device_firmware = "";
            link_type = 0;
            cms_id = "";
            trans_protocol = 0;

            login_ip = "";
            login_port = 0;
            reg_status = 0;
            reg_info_index = -1;
            auth_count = 0;
        }

    }
    GBDevice_cfg_t;

    /* �߼��豸������Ϣ�ṹ�� */
    typedef struct _LogicDeviceGroup_t
    {
        char GroupID[32 + 4];
        char CMSID[MAX_ID_LEN + 4];
        char Name[64 + 4];
        int SortID;
        char ParentID[32 + 4];
        char iChangeFlag;               /* �仯��ʶ:0:�ޱ仯, 1:���ӣ�2:�޸ģ�3:ɾ�� */
    } LogicDeviceGroup_t;

    /* �߼��豸������Ϣ���� */
    typedef std::map <string, LogicDeviceGroup_t*> LogicDeviceGroup_MAP;
    typedef std::map <string, LogicDeviceGroup_t*>::iterator LogicDeviceGroup_Iterator;

    /* �߼��豸�����ϵ��Ϣ�ṹ�� */
    typedef struct _LogicDeviceMapGroup_t
    {
        char GroupID[32 + 4];
        char CMSID[MAX_ID_LEN + 4];
        unsigned int DeviceIndex;
        int SortID;
        char iChangeFlag;               /* �仯��ʶ:0:�ޱ仯, 1:���ӣ�2:�޸ģ�3:ɾ�� */
    } LogicDeviceMapGroup_t;

    /* �߼��豸�����ϵ��Ϣ���� */
    typedef std::map <unsigned int, LogicDeviceMapGroup_t*> LogicDeviceMapGroup_MAP;
    typedef std::map <unsigned int, LogicDeviceMapGroup_t*>::iterator LogicDeviceMapGroup_Iterator;

    /* ��׼�����豸��Ϣ�ṹ�� */
    typedef struct _GBDevice_info_t
    {
        int id;                                          /* �豸���� */
        char device_id[MAX_ID_LEN + 4];                  /* �豸ͳһ��� */
        int device_type;                                 /* �豸����(ǰ���������NVR������CMS��TSU) */
        int link_type;                                   /* ��������: 0:���¼���1��ͬ����Ĭ��0 */
        int access_method;                               /* ���뷽ʽ: 0:���꣬1:˽��Э�飬Ĭ��0 */
        int tcp_sock;                                    /* ˽��Э�����ʱ��Ķ�Ӧ��TCP Socket */
        char login_ip[MAX_IP_LEN];                       /* ��¼��ip��ַ*/
        int login_port;                                  /* ��¼�Ķ˿ں�*/
        int reg_status;                                  /* ע��״̬ */
        int reg_info_index;                              /* ��������ʱ��:��Ӧ��SIPЭ��ջ��ע����Ϣ��Index, ˽��Э������ʱ��:��Ӧ��TCP�����е�Index */
        int auth_count;                                  /* ��֤ʧ�ܴ��� */
        int last_keep_alive_time;                        /* ��󱣻�ʱ�� */
        int keep_alive_expires;                          /* ���ʱʱ�� */
        int keep_alive_expires_count;                    /* ���ʱʱ����� */

        char manufacturer[MAX_128CHAR_STRING_LEN + 4];   /* �豸������ */

        int three_party_flag;                            /* �Ƿ��ǵ�������ƽ̨:0:���ǣ�1:�� */
        int catalog_subscribe_flag;                      /* Ŀ¼���ı�ʶ:0:û�ж��ģ�1:�Ѷ��� */
        int catalog_subscribe_interval;                  /* Ŀ¼����δ�ɹ������Լ��ʱ�� */
        int catalog_subscribe_expires;                   /* Ŀ¼���ĳ�ʱʱ��*/
        int catalog_subscribe_expires_count;             /* Ŀ¼����ʱ����� */
        unsigned int catalog_subscribe_event_id;         /* Ŀ¼�����¼����� */
        unsigned int catalog_subscribe_dialog_index;     /* Ŀ¼���Ķ�Ӧ�ĻỰ���� */
        int trans_protocol;                              /* ý������������:0:UDP��1:TCP */

        char strRegServerEthName[MAX_IP_LEN];            /* ע��ķ�����IP��ַ�������� */
        char strRegServerIP[MAX_IP_LEN];                 /* ע��ķ�����IP��ַ */
        int iRegServerPort;                              /* ע��ķ������˿ں� */

        char call_id[MAX_128CHAR_STRING_LEN + 4];        /* ע��ľ��callid,��ʶ�Ƿ���ˢ��ע�� */

        int CataLogNumCount;                             /* �����豸�ϱ����߼�ͨ������ */
        unsigned int CataLogSN;                          /* ��ȡ�����豸XML��Ϣ��SN */
        int iGetCataLogStatus;                           /* �����豸�ϱ����߼�ͨ��״̬:0:û�л�ȡ��1:�Ѿ���ȡ��2:���ڴ���������Ϣ */
        time_t iLastGetCataLogTime;                      /* �ϴλ�ȡ�����豸�߼�ͨ��ʱ�� */
        int iGetLogicDeviceStatusCount;                  /* ��ȡǰ�������豸�����߼���λ״̬�������� */
        int keep_alive_count;                            /* ����������� */

        int LogicDeviceGroupConfigCount;                 /* �¼��ϱ����߼��豸�������ø��� */
        unsigned int LogicDeviceGroupSN;                 /* ��ȡ�߼��豸����XML��Ϣ��SN */
        LogicDeviceGroup_MAP LogicDeviceGroupList;       /* �¼��ϱ����߼��豸������Ϣ���� */

        int LogicDeviceMapGroupConfigCount;              /* �¼��ϱ����߼��豸�����ϵ���ø��� */
        unsigned int LogicDeviceMapGroupSN;              /* ��ȡ�߼��豸�����ϵXML��Ϣ��SN */
        LogicDeviceMapGroup_MAP LogicDeviceMapGroupList; /* �¼��ϱ����߼��豸�����ϵ��Ϣ���� */

        unsigned int del_mark;                           /* ɾ����ʶ:0,��ɾ����1:ɾ�� */

        unsigned int  nResved1;                          /* ����1 */
        char   strResved2[MAX_32CHAR_STRING_LEN + 4];    /* ����2 */
    } GBDevice_info_t;

    /* ��׼�����豸��Ϣ���� */
    typedef std::map <string, GBDevice_info_t*> GBDevice_Info_MAP;
    typedef std::map <string, GBDevice_info_t*>::iterator GBDevice_Info_Iterator;

    /* ��������׼�����豸��Ϣ���� */
    typedef std::deque <GBDevice_info_t*> needtoproc_GBDeviceinfo_queue;

    typedef struct _GBDevice_t
    {
        int stream_type;                      /* ý�������ͣ�1:����Ƶ����2:����Ƶ����3:������ */
        GBDevice_info_t* ptGBDeviceInfo;      /* ��Ӧ�ı�׼�����豸��Ϣ */
    } GBDevice_t;

    /* ��׼�߼��豸��Ϣ�ṹ�� */
    typedef struct _GBLogicDevice_info_t
    {
        unsigned int id;                                    /* ��λ���� */
        char device_id[MAX_ID_LEN + 4];                     /* ��λͳһ��� */
        char device_name[MAX_128CHAR_STRING_LEN + 4];       /* ��λ���� */
        int enable;                                         /* �Ƿ����� */
        int device_type;                                    /* �豸���� */
        unsigned int alarm_device_sub_type;                 /* �����豸������ EV9000_ALARM_DEVICE_MJ,ʹ�����ݿ�Resved1�ֶ� */
        int ctrl_enable;                                    /* ��������ͣ�1-�����2-����3-�̶�ǹ���� 4-ң��ǹ������Ŀ¼��Ϊ�����ʱ��ѡ */
        int mic_enable;                                     /* �Ƿ�֧�ֶԽ���Ĭ��ֵ0 */
        int frame_count;                                    /* ֡�ʣ�Ĭ��25 */
        int alarm_duration;                                 /* �澯ʱ�� */
        int phy_mediaDeviceIndex;                           /* ��Ӧ��ý�������豸���� */
        int phy_mediaDeviceChannel;                         /* ��Ӧ��ý�������豸ͨ�� */
        int phy_ctrlDeviceIndex;                            /* ��Ӧ�Ŀ��������豸���� */
        int phy_ctrlDeviceChannel;                          /* ��Ӧ�Ŀ��������豸ͨ�� */
        int stream_count;                                   /* �Ƿ�֧�ֶ����� */
        int record_type;                                    /* ¼������ */
        int guard_type;                                     /* ���ţ�����״̬:0:������1:����,Ĭ�ϲ��� */
        int other_realm;                                    /* �Ƿ���������ĵ�λ��Ĭ��0�������1����ʾ�Ǵ��ϼ�CMS���͹�����������ĵ�λ  */

        char manufacturer[MAX_128CHAR_STRING_LEN + 4];      /* �豸������ */
        char model[MAX_128CHAR_STRING_LEN + 4];             /* �豸�ͺ� */
        char owner[MAX_128CHAR_STRING_LEN + 4];             /* �豸���� */
        char civil_code[MAX_128CHAR_STRING_LEN + 4];        /* �������� */
        char block[MAX_128CHAR_STRING_LEN + 4];             /* ���� */
        char address[MAX_128CHAR_STRING_LEN + 4];           /* ��װ��ַ */
        int parental;                                       /* �Ƿ������豸 */
        char parentID[MAX_128CHAR_STRING_LEN + 4];          /* ���豸/����/ϵͳID */
        char virtualParentID[MAX_128CHAR_STRING_LEN + 4];   /* ������֯ID,�ϱ���������ƽ̨ʹ�� */
        int safety_way;                                     /* ���ȫģʽ*/
        int register_way;                                   /* ע�᷽ʽ */

        char cert_num[MAX_128CHAR_STRING_LEN + 4];          /* ֤�����к�*/
        int certifiable;                                    /* ֤����Ч��ʶ */
        int error_code;                                     /* ��Чԭ���� */
        char end_time[MAX_128CHAR_STRING_LEN + 4];          /* ֤����ֹ��Ч��*/

        int secrecy;                                        /* �������� */

        char ip_address[MAX_IP_LEN];                        /* IP��ַ*/
        int port;                                           /* �˿ں� */
        char password[MAX_128CHAR_STRING_LEN + 4];          /* ����*/

        int status;                                         /* ��λ״̬:0�����ߣ�1:���ߣ�2: û������,3: ���ɴ� */
        intelligent_status_t intelligent_status;            /* ���ܷ���״̬:0��û�з�����1:���� */
        alarm_status_t alarm_status;                        /* ����״̬:0��CLOSE��1:APART */
        lock_status_t lock_status;                          /* ����״̬:0����������1:�û�������2:�ϼ����� */
        user_info_t* pLockUserInfo;                         /* ��Ӧ���������û���Ϣ */
        route_info_t* pLockRouteInfo;                       /* ��Ӧ���������ϼ�·����Ϣ */

        double longitude;                                   /* ���� */
        double latitude;                                    /* γ�� */
        char map_layer[MAX_128CHAR_STRING_LEN + 4];         /* ������ͼ�� */

        char cms_id[MAX_ID_LEN + 4];                        /* ������CMS ͳһ��� */

        osip_list_t* pGBDeviceInfoList;                     /* ��Ӧ�ı�׼�����豸���� */
#ifdef MULTI_THR
        osip_mutex_t* pGBDeviceInfoListLock;                /* ��Ӧ�ı�׼�����豸������ */
#endif

        unsigned int  no_stream_count;                      /* TSU �ϱ�û���������� */
        unsigned int  shdb_channel_id;                      /* �Ϻ��ر��Ӧ��ͨ��ID */

        unsigned int del_mark;                              /* ɾ����ʶ:0,��ɾ����1:ɾ����2:���ܷ���ɾ�� */

        char Value[EV9000_LONG_LONG_STRING_LEN];            /*ң��ң�أ�1~����0~�գ�ң��ң������ʵ���ݣ������ͣ��¼������������ַ���*/
        char Unit[EV9000_SHORT_STRING_LEN];                 /*ң��ң��ʱ��Ч ��λ*/
        int AlarmPriority;                                  /*0~�ޱ�����1~3��ʾ��������*/

        unsigned int  nResved1;                             /* ����1 */
        char strResved2[MAX_32CHAR_STRING_LEN + 4];         /* ����2 */
    } GBLogicDevice_info_t;

    /* ��׼�߼��豸��Ϣ���� */
    typedef std::map <string, GBLogicDevice_info_t*> GBLogicDevice_Info_MAP;
    typedef std::map <string, GBLogicDevice_info_t*>::iterator GBLogicDevice_Info_Iterator;

    /* ZRV�豸��Ϣ�ṹ�� */
    typedef struct _ZRVDevice_info_t
    {
        unsigned int id;                                 /* �豸���� */
        char device_ip[MAX_IP_LEN];                      /* �豸ip��ַ*/
        int reg_status;                                  /* ״̬:0:�����ߣ�1:���� */

        int tcp_sock;                                    /* ��Ӧ��TCP Socket */

        int last_register_time;                          /* ���ע��ʱ�� */
        int register_expires;                            /* ע�ᳬʱʱ�� */
        int register_expires_count;                      /* ע�ᳬʱʱ����� */

        char strRegServerEthName[MAX_IP_LEN];            /* ע��ķ�����IP��ַ�������� */
        char strRegServerIP[MAX_IP_LEN];                 /* ע��ķ�����IP��ַ */

        unsigned int del_mark;                           /* ɾ����ʶ:0,��ɾ����1:ɾ�� */
    } ZRVDevice_info_t;

    /* ZRV�豸��Ϣ���� */
    typedef std::map <string, ZRVDevice_info_t*> ZRVDevice_Info_MAP;
    typedef std::map <string, ZRVDevice_info_t*>::iterator ZRVDevice_Info_Iterator;

    /* ������ZRV�豸��Ϣ���� */
    typedef std::deque <ZRVDevice_info_t*> needtoproc_ZRVDeviceinfo_queue;

    extern int AddAllGBLogicDeviceIDToVector(vector<string>& DeviceIDVector, DBOper* ptDBoper);
    extern int AddAllGBLogicDeviceIDToVectorForDevice(vector<string>& DeviceIDVector, int device_type, DBOper* ptDBoper);
    extern int AddAllGBLogicDeviceIDToVectorForRoute(vector<string>& DeviceIDVector, int route_index, int iThreePartyFlag, int link_type, DBOper* ptDBoper);
    extern int AddAllGBLogicDeviceIDToVectorForSubCMS(vector<string>& DeviceIDVector, int device_index, DBOper* ptDBoper);
    extern int AddAllGBLogicDeviceIDToVectorForUser(vector<string>& DeviceIDVector, DBOper* ptDBoper);
    extern int AddAllRCUGBLogicDeviceIDToVectorForUser(vector<string>& DeviceIDVector, DBOper* ptDBoper);
    extern void AddAllSubCMSIPToVector(vector<string>& SubCmsIPVector);
    extern int AddAssignCompressTaskToPerZRVDevice(vector<string>& CompressTaskID, int task_count, int task_begin_index, int task_end_index, vector<string>& PerCompressTaskID);
    extern int AddCivilCodeToGBLogicDeviceInfo(DBOper* pDevice_Srv_dboper);
    extern int AddGBLogicDeviceInfo2DB(char * device_id, DBOper * pDevice_Srv_dboper);
    extern int AddGBLogicDeviceInfo2DBForRoute(char * device_id, DBOper * pDevice_Srv_dboper);
    extern int AddGBLogicDeviceInfoByGBDeviceInfo(GBDevice_info_t * pGBDeviceInfo);
    extern int AddLogicDeviceGroup(GBDevice_info_t* pGBDeviceInfo, char* group_id, char* cms_id, char* group_name, int sort_id, char* parent_id);
    extern int AddLogicDeviceGroupAndMapDataDeviceInfo(DBOper* pDevice_Srv_dboper);
    extern int AddLogicDeviceGroupConfigToDeviceInfo(GBDevice_info_t* pGBDeviceInfo, DBOper* pDevice_Srv_dboper);
    extern int AddLogicDeviceGroupMapConfigToDeviceInfo(GBDevice_info_t* pGBDeviceInfo, DBOper* pDevice_Srv_dboper);
    extern int AddLogicDeviceMapGroup(GBDevice_info_t* pGBDeviceInfo, char* group_id, unsigned int device_index, char* cms_id, int sort_id);
    extern int checkGBDeviceIsOnline(char* device_ip);
    extern int CheckIsGBLogicDeviceInfoInDB(char * device_id, DBOper * pDevice_Srv_dboper);
    extern int checkNumberOfGBDeviceInfo();
    extern void check_GBDeviceConfig_need_to_reload(DBOper* pDboper);
    extern int check_GBDevice_info_from_db_to_list(DBOper* pdboper);
    extern void check_GBLogicDeviceConfig_need_to_reload(DBOper* pDboper);
    extern int check_GBLogicDevice_info_from_db_to_list(DBOper* pdboper);
    extern int check_shdb_channel_info_from_db(DBOper * pDboper);
    extern int CivilCodeGBLogicDeviceCatalogInfoProc(GBDevice_info_t * pGBDeviceInfo, char* civil_code, char* civil_name, char* parent_id, int iEvent, DBOper* pDboper, int iNeedToSync);
    extern int debug_GBDevice_info_list_lock(const char* file, int line, const char* func);
    extern int debug_GBDevice_info_list_unlock(const char* file, int line, const char* func);
    extern int debug_GBLogicDevice_info_list_lock(const char* file, int line, const char* func);
    extern int debug_GBLogicDevice_info_list_unlock(const char* file, int line, const char* func);
    extern int debug_ZRVDevice_info_list_lock(const char* file, int line, const char* func);
    extern int debug_ZRVDevice_info_list_unlock(const char* file, int line, const char* func);
    extern int DeleteExcessLogicDeviceMapGroupConfig(LogicDeviceMapGroup_t* pLogicDeviceMapGroup, DBOper* pDevice_Srv_dboper);
    extern int DeleteLogicDeviceGroupConfig(LogicDeviceGroup_t* pLogicDeviceGroup, DBOper* pDevice_Srv_dboper);
    extern int DeleteLogicDeviceMapGroupConfig(LogicDeviceMapGroup_t* pLogicDeviceMapGroup, DBOper* pDevice_Srv_dboper);
    extern int delete_GBDevice_info_from_list_by_mark();
    extern int delete_GBLogicDevice_info_from_list_by_mark();
    extern int DelLogicDeviceGroupInfo(GBDevice_info_t* pGBDeviceInfo);
    extern int DelLogicDeviceGroupInfo2(GBDevice_info_t* pGBDeviceInfo, LogicDeviceGroup_t* pLogicDeviceGroup);
    extern int DelLogicDeviceMapGroupInfo(GBDevice_info_t* pGBDeviceInfo);
    extern int DelLogicDeviceMapGroupInfo2(GBDevice_info_t* pGBDeviceInfo, LogicDeviceMapGroup_t* pLogicDeviceMapGroup);
    extern int DeviceGroupConfigInfoProc(GBDevice_info_t* pGBDeviceInfo, char* group_id, char* group_name, char* parent_id, int sort_id, int iEvent, DBOper* pDboper, int iNeedToSync);
    extern int DeviceGroupMapConfigInfoProc(GBDevice_info_t* pGBDeviceInfo, char* group_id, unsigned int device_index, int sort_id, int iEvent, DBOper* pDboper, int iNeedToSync);
    extern int ExecuteControlRCUDevice(unsigned int uDeviceIndex, char* ctrl_value, DBOper * pDBoper);
    extern int ExecuteDeviceAlarmRecord(unsigned int uDeviceIndex, int flag, DBOper * pDevice_Srv_dboper);
    extern int ExecuteDevicePresetByPresetID(unsigned int uPresetID, DBOper * pDevice_Srv_dboper);
    extern int ExecuteDevicePresetByPresetIDAndDeviceIndex(unsigned int uPresetID, unsigned int uDeviceIndex, DBOper * pDevice_Srv_dboper);
    extern int free_zrv_device_info_by_tcp_socket(int tcp_socket);
    extern int GBDeviceConfig_db_refresh_proc();
    extern int GBDevice_add(GBLogicDevice_info_t* pGBLogicDeviceInfo, int stream_type, GBDevice_info_t* pGBDeviceInfo);
    extern void GBDevice_free(GBDevice_t* gb_device);
    extern GBDevice_t* GBDevice_get_by_stream_type(GBLogicDevice_info_t* pGBLogicDeviceInfo, int stream_type);
    extern int GBDevice_info_add(GBDevice_info_t* pGBDeviceInfo);
    extern GBDevice_info_t* GBDevice_info_find(char* device_id);
    extern GBDevice_info_t* GBDevice_info_find_by_device_index(int device_index);
    extern GBDevice_info_t* GBDevice_info_find_by_id_ip_and_port(char* device_id, char* login_ip, int login_port);
    extern GBDevice_info_t* GBDevice_info_find_by_ip_and_port(char* login_ip, int login_port);
    extern void GBDevice_info_free(GBDevice_info_t* GBDevice_info);
    extern GBDevice_info_t* GBDevice_info_get_by_stream_type(GBLogicDevice_info_t* pGBLogicDeviceInfo, int stream_type);
    extern GBDevice_info_t* GBDevice_info_get_by_stream_type2(GBLogicDevice_info_t* pGBLogicDeviceInfo, int stream_type);
    extern int GBDevice_info_init(GBDevice_info_t** GBDevice_info);
    extern void GBDevice_info_list_free();
    extern int GBDevice_info_list_init();
    extern int GBDevice_info_list_lock();
    extern int GBDevice_info_list_unlock();
    extern int GBDevice_info_remove(char* device_id);
    extern int GBDevice_init(GBDevice_t** gb_device);
    extern int GBDevice_remove(GBLogicDevice_info_t* pGBLogicDeviceInfo, int stream_type);
    extern int GBLogicDeviceCatalogGroupMapProc(GBDevice_info_t * pGBDeviceInfo, GBLogicDevice_info_t* pGBLogicDeviceInfo, char* parent_id, DBOper* pDevice_Srv_dboper, int iNeedToSync);
    extern int GBLogicDeviceCatalogInfoProc(GBDevice_info_t* pGBDeviceInfo, GBLogicDevice_info_t* pNewGBLogicDeviceInfo, GBLogicDevice_info_t* pOldGBLogicDeviceInfo, DBOper* pDevice_Srv_dboper);
    extern int GBLogicDeviceCatalogInfoProcForRoute(GBLogicDevice_info_t* pNewGBLogicDeviceInfo, GBLogicDevice_info_t* pOldGBLogicDeviceInfo, DBOper* pDevice_Srv_dboper);
    extern int GBLogicDeviceConfig_db_refresh_proc();
    extern int GBLogicDevice_info_add(GBLogicDevice_info_t* pGBLogicDeviceInfo);
    extern GBLogicDevice_info_t* GBLogicDevice_info_find(char* device_id);
    extern GBLogicDevice_info_t* GBLogicDevice_info_find_by_device_index(unsigned int device_index);
    extern GBLogicDevice_info_t* GBLogicDevice_info_find_by_device_index2(unsigned int device_index);
    extern void GBLogicDevice_info_free(GBLogicDevice_info_t* GBLogicDevice_info);
    extern int GBLogicDevice_info_init(GBLogicDevice_info_t** GBLogicDevice_info);
    extern void GBLogicDevice_info_list_free();
    extern int GBLogicDevice_info_list_init();
    extern int GBLogicDevice_info_list_lock();
    extern int GBLogicDevice_info_list_unlock();
    extern int GBLogicDevice_info_remove(char* device_id);
    extern int GBLogicDevice_info_update(GBLogicDevice_info_t* pOldGBLogicDeviceInfo, GBLogicDevice_info_t* pNewGBLogicDeviceInfo, int change_type);
    extern int GBLogicDevice_info_update_for_route(GBLogicDevice_info_t* pOldGBLogicDeviceInfo, GBLogicDevice_info_t* pNewGBLogicDeviceInfo, int change_type);
    extern int GetGBDeviceListAndSendNotifyCatalogToSubCMS(GBDevice_info_t* pGBDeviceInfo, DBOper* pDevice_Srv_dboper);
    extern int GetGBLogicDeviceRecordTypeFromDB(char * device_id, DBOper * pDevice_Srv_dboper);
    extern LogicDeviceGroup_t* GetLogicDeviceGroup(GBDevice_info_t* pGBDeviceInfo, char* group_id);
    extern LogicDeviceMapGroup_t* GetLogicDeviceMapGroup(GBDevice_info_t* pGBDeviceInfo, unsigned int device_index);
    extern int GetZRVDeviceIPForAssginTask(vector<string>& ZRVDeviceIP);
    extern int Get_GBDevice_Index_By_Device_ID(char* device_id);
    extern unsigned int Get_GBLogicDevice_Index_By_Device_ID(char* device_id);
    extern int GroupCodeGBLogicDeviceCatalogInfoProc(GBDevice_info_t * pGBDeviceInfo, char* group_id, char* group_name, char* parent_id, int iEvent, DBOper* pDboper, int iNeedToSync);
    extern int InsertLogicDeviceGroupConfig(LogicDeviceGroup_t* pLogicDeviceGroup, DBOper* pDevice_Srv_dboper);
    extern int InsertLogicDeviceMapGroupConfig(LogicDeviceMapGroup_t* pLogicDeviceMapGroup, DBOper* pDevice_Srv_dboper);
    extern int IntelligentAnalysisGBLogicDeviceCatalogInfoProc(GBDevice_info_t * pGBDeviceInfo, char* device_id, DBOper* pDboper);
    extern int IsGBDeviceRegInfoHasChange(GBDevice_info_t * pGBDeviceInfo, int iDeviceType, char * pcLoginIP, int iLoginPort, int iRegInfoIndex);
    extern int IsGBLogicDeviceInfoHasChange(GBLogicDevice_info_t * pOldGBLogicDeviceInfo, GBLogicDevice_info_t * pNewGBLogicDeviceInfo, int change_type);
    extern int IsGBLogicDeviceInfoHasChangeForRCU(GBLogicDevice_info_t * pOldGBLogicDeviceInfo, GBLogicDevice_info_t * pNewGBLogicDeviceInfo);
    extern int IsGBLogicDeviceInfoHasChangeForRoute(GBLogicDevice_info_t * pOldGBLogicDeviceInfo, GBLogicDevice_info_t * pNewGBLogicDeviceInfo, int change_type);
    extern int IsIPInSubCMS(vector<string>& SubCmsIPVector, char* ip_addr);
    extern int is_zrv_device_tcp_socket_in_use(int tcp_socket);
    extern int load_db_data_to_LogicDevice_info_list_by_device_id(DBOper * ptDBOper, char* device_id);
    extern int load_GBLogicDevice_info_from_db_by_device_id(DBOper * ptDBOper, char* device_id, GBLogicDevice_info_t** pGBLogicDeviceInfo);
    extern void LogicDeviceGroup_free(LogicDeviceGroup_t* logic_device_group);
    extern int LogicDeviceGroup_init(LogicDeviceGroup_t** logic_device_group);
    extern void LogicDeviceMapGroup_free(LogicDeviceMapGroup_t* logic_device_map_group);
    extern int LogicDeviceMapGroup_init(LogicDeviceMapGroup_t** logic_device_map_group);
    extern int ModifyLogicDeviceGroup(LogicDeviceGroup_t* pLogicDeviceGroup, char* group_name, int sort_id, char* parent_id);
    extern int ModifyLogicDeviceMapGroup(LogicDeviceMapGroup_t* pLogicDeviceMapGroup, char* group_id, char* cms_id, int sort_id);
    extern int RemoveGBLogicDevice(int device_index);
    extern int RemoveGBLogicDeviceLockInfoByRouteInfo(route_info_t* pRouteInfo);
    extern int RemoveGBLogicDeviceLockInfoByUserInfo(user_info_t* pUserInfo);
    extern void scan_GBDevice_info_list_for_expires();
    extern void scan_GBDevice_info_list_for_subscribe();
    extern void scan_ZRVDevice_info_list_for_expires();
    extern int SendAllDeviceStatusToSubCMS(vector<string>& DeviceIDVector, int status, DBOper* ptDBoper);
    extern int SendAllGBLogicDeviceIntelligentStatusOffAlarmToAllClientUser(int device_index);
    extern int SendAllGBLogicDeviceStatusOffAlarmToAllClientUser(int device_index);
    extern int SendAllGBLogicDeviceStatusProc(int device_index, int status, int enable, DBOper* ptDBoper);
    extern int SendAllIntelligentGBLogicDeviceStatusProc(int device_index, int status, DBOper* ptDBoper);
    extern int SendAllNotifyCatalogToSubCMS(vector<string>& DeviceIDVector, int iEvent, DBOper* ptDBoper);
    extern int SendDeviceControlAlarmMessage(char * device_id, GBDevice_info_t * pGBDeviceInfo, int iuCmdType);
    extern int SendDeviceNoStreamAlarmToAllClientUser(char * device_id);
    extern int SendDeviceOffLineAlarmToAllClientUser(char * device_id);
    extern int SendDeviceStatusMessageProc(GBLogicDevice_info_t* pGBLogicDeviceInfo, int status, DBOper* pDboper);
    extern int SendDeviceStatusToSubCMS(GBLogicDevice_info_t* pGBLogicDeviceInfo, int status, DBOper* ptDBoper);
    extern int SendDeviceTeleBootMessage(GBDevice_info_t * pGBDeviceInfo);
    extern int SendExecuteDevicePresetMessage(GBLogicDevice_info_t* pGBLogicDeviceInfo, GBDevice_info_t * pGBDeviceInfo, unsigned int uPresetID);
    extern int SendExecuteDevicePresetMessageToRoute(GBLogicDevice_info_t* pGBLogicDeviceInfo, route_info_t * pRouteInfo, unsigned int uPresetID);
    extern int SendExecuteDevicePresetMessageToSubCMS(char* strPresetID);
    extern int SendGBPhyDeviceOffLineAlarmToAllClientUser(unsigned int uType, unsigned int device_index);
    extern int SendIntelligentDeviceOffLineAlarmToAllClientUser(char * device_id);
    extern int SendNotifyCatalogMessageToAllRoute(GBLogicDevice_info_t* pGBLogicDeviceInfo, int iEvent, DBOper* ptDBoper);
    extern int SendNotifyCatalogMessageToSubCMS(char* strCMSID);
    extern int SendNotifyCatalogToRouteCMS(GBLogicDevice_info_t* pGBLogicDeviceInfo, int iEvent, DBOper* pDboper);
    extern int SendNotifyCatalogToSubCMS(GBLogicDevice_info_t* pGBLogicDeviceInfo, int iEvent, DBOper* ptDBoper);
    extern int SendNotifyGroupMapCatalogTo3PartyRouteCMS(GBLogicDevice_info_t* pGBLogicDeviceInfo, int iEvent, DBOper* pDboper);
    extern int SendNotifyRestartMessageToAllSubCMS();
    extern int SendNotifyRestartMessageToSubCMS(GBDevice_info_t * pGBDeviceInfo);
    extern int SendQueryAllOfflineLogicDeviceStatusMessage(GBDevice_info_t * pGBDeviceInfo);
    extern int SendQueryDECDeviceMediaPortMessage(GBDevice_info_t * pGBDeviceInfo, char* dc_id, char* camera_id, int iStreamType);
    extern int SendQueryDeviceCatalogMessage(GBDevice_info_t * pGBDeviceInfo);
    extern int SendQueryDeviceGroupInfoMessage(GBDevice_info_t * pGBDeviceInfo);
    extern int SendQueryDeviceGroupMapInfoMessage(GBDevice_info_t * pGBDeviceInfo);
    extern int SendQueryDeviceInfoMessage(GBDevice_info_t * pGBDeviceInfo);
    extern int SendQueryDeviceStatusMessage(GBDevice_info_t * pGBDeviceInfo);
    extern int SendQueryGBLogicDeviceStatusMessage(char* device_id, GBDevice_info_t * pGBDeviceInfo);
    extern int SendQuerySubCMSDBIPMessage(GBDevice_info_t * pGBDeviceInfo);
    extern int SendQuerySubCMSTopologyPhyDeviceConfigMessage(GBDevice_info_t * pGBDeviceInfo);
    extern int SendRCUDeviceStatusToRouteCMS(GBLogicDevice_info_t* pGBLogicDeviceInfo, DBOper* pDboper);
    extern int SendRCUDeviceStatusToSubCMS(GBLogicDevice_info_t* pGBLogicDeviceInfo, DBOper* ptDBoper);
    extern int SendSubscribeMessageToSubGBDevice(GBDevice_info_t* pGBDeviceInfo, int iFlag);
    extern int SendTSUInfoMessageToDEC(char* callee_id, char* local_ip, int local_port, char* remote_ip, int remote_port, char* strSN, char* device_id, char* tsu_ip, int tsu_port);
    extern int SetGBLogicDeviceInfoDelFlag(GBDevice_info_t* pGBDeviceInfo);
    extern int SetGBLogicDeviceInfoEnableFlagByDelMark(GBDevice_info_t* pGBDeviceInfo, DBOper* pDevice_Srv_dboper);
    extern int SetGBLogicDeviceIntelligentStatus(int device_index, intelligent_status_t status);
    extern int SetGBLogicDeviceStatus(int device_index, int status, DBOper * pDevice_Srv_dboper);
    extern int SetLogicDeviceGroupChangeFlag(GBDevice_info_t* pGBDeviceInfo, int iChangeFlag);
    extern int SetLogicDeviceMapGroupChangeFlag(GBDevice_info_t* pGBDeviceInfo, int iChangeFlag);
    extern unsigned int SetZRVDeviceToConfigTable(ZRVDevice_info_t* pZRVDeviceInfo, DBOper* ptDBoper);
    extern int set_GBDevice_info_list_del_mark(int del_mark);
    extern int set_GBLogicDevice_info_list_del_mark(int del_mark);
    extern int set_vms_nvr_GBLogicDevice_info_enable_mark(char* device_id, int enable_mark);
    extern void ShowGBDeviceInfo(int sock, int type);
    extern void ShowLogicDeviceInfo(int sock, int type);
    extern void ShowZRVDeviceInfo(int sock, int type);
    extern int SynLogicDeviceGroupInfoToDB(GBDevice_info_t* pGBDeviceInfo, DBOper* pDevice_Srv_dboper);
    extern int SynLogicDeviceGroupInfoToDB2(LogicDeviceGroup_t* pLogicDeviceGroup, DBOper* pDevice_Srv_dboper);
    extern int SynLogicDeviceMapGroupInfoToDB(GBDevice_info_t* pGBDeviceInfo, DBOper* pDevice_Srv_dboper);
    extern int SynLogicDeviceMapGroupInfoToDB2(LogicDeviceMapGroup_t* pLogicDeviceMapGroup, DBOper* pDevice_Srv_dboper);
    extern int UpdateGBDeviceCMSID2DB(char* device_id, DBOper * pDevice_Srv_dboper);
    extern int UpdateGBDeviceInfo2DB(GBDevice_cfg_t & new_GBDevice_cfg, DBOper * pDevice_Srv_dboper);
    extern int UpdateGBDeviceLinkType2DB(GBDevice_info_t * pGBDeviceInfo, DBOper * pDevice_Srv_dboper);
    extern int UpdateGBDeviceRegStatus2DB(GBDevice_info_t * pGBDeviceInfo, DBOper * pDevice_Srv_dboper);
    extern int UpdateGBLogicDeviceRegStatus2DB(char * strDeviceID, int status, DBOper * pDevice_Srv_dboper);
    extern int UpdateGBLogicDeviceXYParam2DB(char * strDeviceID, double longitude, double latitude, char * strMapLayer, DBOper * pDevice_Srv_dboper);
    extern int UpdateLogicDeviceGroupConfig(LogicDeviceGroup_t* pLogicDeviceGroup, DBOper* pDevice_Srv_dboper);
    extern int UpdateLogicDeviceMapGroupConfig(LogicDeviceMapGroup_t* pLogicDeviceMapGroup, DBOper* pDevice_Srv_dboper);
    extern int ZRVDevice_info_add(ZRVDevice_info_t* pZRVDeviceInfo);
    extern ZRVDevice_info_t* ZRVDevice_info_find(char* device_ip);
    extern ZRVDevice_info_t* ZRVDevice_info_find_by_tcp_sock(int tcp_sock);
    extern void ZRVDevice_info_free(ZRVDevice_info_t* ZRVDevice_info);
    extern int ZRVDevice_info_init(ZRVDevice_info_t** ZRVDevice_info);
    extern void ZRVDevice_info_list_free();
    extern int ZRVDevice_info_list_init();
    extern int ZRVDevice_info_list_lock();
    extern int ZRVDevice_info_list_unlock();
    extern int ZRVDevice_info_remove(char* device_ip);
    extern char* get_zrv_device_ip_by_min_task_count(char* platform_ip);

#ifdef ENABLE_DEBUG_LOCK
#define GBDEVICE_SMUTEX_LOCK() debug_GBDevice_info_list_lock(__FILE__, __LINE__, __func__)
#define GBDEVICE_SMUTEX_UNLOCK() debug_GBDevice_info_list_unlock(__FILE__, __LINE__, __func__)
#define GBLOGICDEVICE_SMUTEX_LOCK() debug_GBLogicDevice_info_list_lock(__FILE__, __LINE__, __func__)
#define GBLOGICDEVICE_SMUTEX_UNLOCK() debug_GBLogicDevice_info_list_unlock(__FILE__, __LINE__, __func__)
#define ZRVDEVICE_SMUTEX_LOCK() debug_ZRVDevice_info_list_lock(__FILE__, __LINE__, __func__)
#define ZRVDEVICE_SMUTEX_UNLOCK() debug_ZRVDevice_info_list_unlock(__FILE__, __LINE__, __func__)
#else
#define GBDEVICE_SMUTEX_LOCK() GBDevice_info_list_lock()
#define GBDEVICE_SMUTEX_UNLOCK() GBDevice_info_list_unlock()
#define GBLOGICDEVICE_SMUTEX_LOCK() GBLogicDevice_info_list_lock()
#define GBLOGICDEVICE_SMUTEX_UNLOCK() GBLogicDevice_info_list_unlock()
#define ZRVDEVICE_SMUTEX_LOCK() ZRVDevice_info_list_lock()
#define ZRVDEVICE_SMUTEX_UNLOCK() ZRVDevice_info_list_unlock()
#endif

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __UDP_TL_H__ */