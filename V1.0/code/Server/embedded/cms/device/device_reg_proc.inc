#ifndef __DEVICE_REG_PROC_H__
#define __DEVICE_REG_PROC_H__


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

#include "device/device_info_mgn.inc"

#include <vector>
#include <string>
#include <queue>

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

    /* ��׼�����豸ע����Ϣ�ṹ�� */
    typedef struct _GBDevice_reg_msg_t
    {
        char register_id[MAX_ID_LEN + 4];                   /* ͳһ���id */
        int device_type;                                    /* �豸���� */
        char login_ip[MAX_IP_LEN];                          /* ��¼��IP��ַ */
        int login_port;                                     /* ��¼�Ķ˿� */
        char register_name[MAX_128CHAR_STRING_LEN + 4];     /* ��¼���û���*/
        int expires;                                        /* ��ʱʱ�� */
        int link_type;                                      /* �������� */
        int reg_info_index;                                 /* Э��ջע������ */
    } GBDevice_reg_msg_t;

    /* ��׼�����豸ע����Ϣ���� */
    typedef std::deque <GBDevice_reg_msg_t*> GBDevice_reg_msg_queue;

    extern int DevRefresh(GBDevice_info_t* pGBDeviceInfo, DBOper* pdboper);
    extern int DevReg(GBDevice_info_t* pGBDeviceInfo, GBDevice_cfg_t& GBDevice_cfg, DBOper* pdboper);
    extern int DevUnReg(GBDevice_info_t* pGBDeviceInfo, DBOper* pdboper);
    extern int GBDevice_reg_msg_add(char* device_id, int device_type, char* login_ip, int login_port, char* register_name, int expires, int reg_info_index, int link_type);
    extern void GBDevice_reg_msg_free(GBDevice_reg_msg_t* GBDevice_reg_msg);
    extern int GBDevice_reg_msg_init(GBDevice_reg_msg_t** GBDevice_reg_msg);
    extern void GBDevice_reg_msg_list_clean();
    extern void GBDevice_reg_msg_list_free();
    extern int GBDevice_reg_msg_list_init();
    extern int GBDevice_reg_msg_proc(GBDevice_reg_msg_t* pMsg, DBOper* pdboper);
    extern void GBDevice_unreg_msg_list_clean();
    extern int GBDevice_unreg_msg_proc(GBDevice_reg_msg_t* pMsg, DBOper* pdboper);
    extern int GetDevCfg(DBOper* pdboper, string strDevID, GBDevice_cfg_t& GBDevice_cfg);
    extern int RegisterSetIPConflictGBDevice2GBPhyDeviceTmpDB(char* device_id, char* pUserName, char* pIPAddr, int link_type, DBOper* pdboper);
    extern int RegisterSetNotFoundGBDevice2GBPhyDeviceTmpDB(char* device_id, char* pUserName, char* pIPAddr, int link_type, DBOper* pdboper);
    extern void scan_GBDevice_reg_msg_list(DBOper* pDevice_Reg_dboper);
    extern void scan_GBDevice_unreg_msg_list(DBOper* pDevice_Reg_dboper);
    extern int WriteErrorInfo2GBPhyDeviceTmpDB(char* device_id, char* user_name, char* ip_addr, device_error_reason_type_t eReason, int link_type, DBOper* pdboper);
    extern int WriteGBPhyDeviceInfoToDB(char* device_id, char* user_name, char* ip_addr, int link_type, DBOper* pdboper);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __UDP_TL_H__ */