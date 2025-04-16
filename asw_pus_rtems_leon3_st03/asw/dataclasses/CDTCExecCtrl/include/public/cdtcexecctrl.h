#ifndef FCDTCExecCtrlH
#define FCDTCExecCtrlH

enum TTCExecCtrl {
	//TODO 05-B Add ExecCtrlHK_FDIRTC to enum
	ExecCtrlPrioTC, ExecCtrlReboot,  ExecCtrlBKGTC , ExecCtrlHK_FDIRTC
};

class CDTCExecCtrl{
	
	friend class CDTCHandler;

	protected:
	
		enum TTCExecCtrl mExecCtrl;

	public:

	/**
	 * \brief Check if it is a reboot telecommand
	 *
	 * \return true if it is a reboot telecommand
	 *
	 */
	bool IsRebootTC(){return (ExecCtrlReboot==mExecCtrl);}

	/**
	 * \brief Check if it is a priority telecommand
	 *
	 * \return true if it is a priority telecommand
	 *
	 */
	bool IsPrioTC(){return (ExecCtrlPrioTC==mExecCtrl);}

	/**
	 * \brief Check if is a HK_FDIR telecommand
	 *
	 * \return true if it is a HK_FDIR telecommand
	 *
	 */
	//TODO 06-B Complete IsHK_FDIRTC() using  ExecCtrlHK_FDIRTC enum
	bool IsHK_FDIRTC(){return (ExecCtrlHK_FDIRTC==mExecCtrl);}


	
	
};
#endif
