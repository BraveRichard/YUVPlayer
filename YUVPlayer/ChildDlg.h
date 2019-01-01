#ifndef _CHILDDLG_H_
#define _CHILDDLG_H_


#include "define.h"
#include "MBInfoDlg.h"


class CChildDlg : public CDialog
{
public:
    CChildDlg(UINT nID, CWnd* pParent /*=NULL*/);

    int8	s8DlgIdx;
	uint8	bSizeChanged;	//++ ���ڴ�С�Ƿ�ı�
    uint8   u8SampleFormat;
	uint8   u8Sample_x;		//++ͼ��ˮƽ���������ʽ
	uint8   u8Sample_y;		//++ͼ��ֱ���������ʽ
#if BITDEPTH//add
	uint8   u8BitDepth;
#endif
    int32	s32MBXNum;		//++ һ�к�����
    int32	s32MBYNum;		//++ һ�к�����
    int32	s32MBXIdx;		//++ ��ǰ��������кţ�����ǰ��
    int32	s32MBYIdx;		//++ ��ǰ��������кţ�����ǰ��
#if LCU
	int32	s32MBXIdx_Lcu;		//++ ��ǰ��������кţ�����ǰ��
	int32	s32MBYIdx_Lcu;		//++ ��ǰ��������кţ�����ǰ��
	int32	s32CurrMBx_Lcu;		//++ ��꾭���ĺ��Ķ������꣨����ǰ��
	int32	s32CurrMBy_Lcu;		//++ ��꾭���ĺ��Ķ������꣨����ǰ��
	int32	s32CurrBlkX_Lcu;	//++ ��꾭���ĺ��Ķ������꣨���ź�
	int32	s32CurrBlkY_Lcu;	//++ ��꾭���ĺ��Ķ������꣨���ź�
	int32	s32CurrBlkW_Lcu;
	int32	s32CurrBlkH_Lcu;

	int32	s32PrevBlkX_Lcu;		//++ ǰһ�����ָ��ĺ��Ķ������꣨���ź�
	int32	s32PrevBlkY_Lcu;		//++ ǰһ�����ָ��ĺ��Ķ������꣨���ź�
	int32	s32PrevBlkW_Lcu;
	int32	s32PrevBlkH_Lcu;

	int32	s32ViewMBx_Lcu;		//++ ��ʾ����ֵ�ĺ��Ķ������꣨����ǰ��
	int32	s32ViewMBy_Lcu;		//++ ��ʾ����ֵ�ĺ��Ķ������꣨����ǰ��
	int32	s32ViewBlkX_Lcu;	//++ ��ʾ����ֵ�ĺ��Ķ������꣨���ź�
	int32	s32ViewBlkY_Lcu;	//++ ��ʾ����ֵ�ĺ��Ķ������꣨���ź�
	int32	s32ViewBlkW_Lcu;
	int32	s32ViewBlkH_Lcu;
#endif
    int32	s32ViewMBx;		//++ ��ʾ����ֵ�ĺ��Ķ������꣨����ǰ��
    int32	s32ViewMBy;		//++ ��ʾ����ֵ�ĺ��Ķ������꣨����ǰ��
    int32	s32ViewBlkX;	//++ ��ʾ����ֵ�ĺ��Ķ������꣨���ź�
    int32	s32ViewBlkY;	//++ ��ʾ����ֵ�ĺ��Ķ������꣨���ź�
	int32	s32ViewBlkW;
	int32	s32ViewBlkH;
    int32	s32PrevBlkX;		//++ ǰһ�����ָ��ĺ��Ķ������꣨���ź�
    int32	s32PrevBlkY;		//++ ǰһ�����ָ��ĺ��Ķ������꣨���ź�
	int32	s32PrevBlkW;
	int32	s32PrevBlkH;
    int32	s32CurrMBx;		//++ ��꾭���ĺ��Ķ������꣨����ǰ��
    int32	s32CurrMBy;		//++ ��꾭���ĺ��Ķ������꣨����ǰ��
    int32	s32CurrBlkX;	//++ ��꾭���ĺ��Ķ������꣨���ź�
    int32	s32CurrBlkY;	//++ ��꾭���ĺ��Ķ������꣨���ź�
	int32	s32CurrBlkW;
	int32	s32CurrBlkH;
    int32	s32Width;		//++ ͼ������ǰ�Ŀ��
    int32	s32Height;		//++ ͼ������ǰ�ĸ߶�
    int32	s32ZoomWidth;	//++ ͼ�����ź�Ŀ��
    int32	s32ZoomHeight;	//++ ͼ�����ź�ĸ߶�
    uint32	u32FrameSize;
    uint32	u32ChroPicSize;
    uint32	u32LumaPicSize;
    HANDLE	hloc;
    LPBITMAPINFO	BmpInfo;
    CMBInfoDlg		MBInfoDlg;
    PCRITICAL_SECTION pCriticalSection;
    LPBYTE	pYUVBuff;
    LPBYTE	pRGBBuff;
    LPBYTE	pReadYUV[3];
    LPBYTE	pOrigYUV[3];
    LPBYTE	pMirrYUV[3];
    LPBYTE	pRotaYUV[3];
    LPBYTE	pDisplayLuma;
    LPBYTE	pDisplayChro;
    CString	fileName;
    CMenu	mouseMenu;
    CWnd	*pMainDlg;
    CMenu	*pSubMenu;
	CRect	wndRect; 
	CRect	newSizeRect; 
	CRect	oldSizeRect; 

    void	resize_window();
    void	get_pixel_value();
    void	set_bmp_parameter();
    void    enable_mbinfo_dlg();
    void    disable_mbinfo_dlg();
    void	remark_macroblock(CPaintDC *pDC);
    void	show_mouse_menu();
    void	mark_macroblock();
    void	show_macroblock_info();
    void	view_macroblock();
    void	color_space_convert(uint8 u8ImageMode);
	void	YV12_to_RGB24(uint8* pu8Y, uint8* pu8U, uint8* pu8V, uint8 u8ImageMode=0);
	void	YUY2_to_RGB24(uint8 *pu8RGBData, uint8 *pu8YUVData);
    void	set_image_mode(uint8 u8ImageMode);
    void	draw_dash_frame(CRect &rect);
	void	change_size(LPRECT pRect);
	void	change_location(LPRECT pRect);
	void	update_image();
    int32	malloc_memory();
    int32	show_image(CDC *pDC);
	DECLARE_MESSAGE_MAP()
	LPBYTE getRGBBuff();
};


#endif