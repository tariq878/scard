#ifndef SCARDDEFS_H
#define SCARDDEFS_H

#ifndef SCARD_E_NO_READERS_AVAILABLE
#define SCARD_E_NO_READERS_AVAILABLE				((DWORD)0x8010002EL)
//
// MessageId: SCARD_E_NO_READERS_AVAILABLE
//
// MessageText:
//
//   Cannot find a smart card reader.
#endif

#ifndef SCARD_E_NO_RESRC_MNGR_RUNNING
#define SCARD_E_NO_RESRC_MNGR_RUNNING				((DWORD)0x8010001DL)
//
// MessageId: SCARD_E_NO_RESRC_MNGR_RUNNING
//
// MessageText:
//
//   The Smart card resource manager is not running.
#endif

#ifndef SCARD_W_WRONG_CHV
#define SCARD_W_WRONG_CHV							((DWORD) 0x8010006BL) 
//
// MessageId: SCARD_W_WRONG_CHV
//
// MessageText:
//
//   The card cannot be accessed because the wrong PIN was presented. 
#endif

#ifndef SCARD_W_CHV_BLOCKED
#define SCARD_W_CHV_BLOCKED							(DWORD)0x8010006CL)
//
// MessageId: SCARD_W_CHV_BLOCKED
//
// MessageText:
//
//   The card cannot be accessed because the maximum number of PIN entry attempts has been reached.  
#endif

#ifndef SCARD_E_BAD_SEEK
#define SCARD_E_BAD_SEEK							((DWORD)0x80100029L)
//
// MessageId: SCARD_E_BAD_SEEK
//
// MessageText:
//
// There was an error trying to set the smart card file object pointer.
#endif

#ifndef SCARD_E_CERTIFICATE_UNAVAILABLE
#define SCARD_E_CERTIFICATE_UNAVAILABLE				((DWORD)0x8010002DL)
//
// MessageId: SCARD_E_CERTIFICATE_UNAVAILABLE
//
// MessageText:
//
// The requested certificate could not be obtained.
#endif

#ifndef SCARD_E_COMM_DATA_LOST
#define SCARD_E_COMM_DATA_LOST						((DWORD)0x8010002FL)
//
// MessageId: SCARD_E_COMM_DATA_LOST
//
// MessageText:
//
// A communications error with the smart card has been detected.  Retry the operation.
#endif

#ifndef SCARD_E_DIR_NOT_FOUND
#define SCARD_E_DIR_NOT_FOUND						((DWORD)0x80100023L)
//
// MessageId: SCARD_E_DIR_NOT_FOUND
//
// MessageText:
//
// The identified directory does not exist in the smart card.
#endif

#ifndef SCARD_E_FILE_NOT_FOUND
#define SCARD_E_FILE_NOT_FOUND						((DWORD)0x80100024L)
//
// MessageId: SCARD_E_FILE_NOT_FOUND
//
// MessageText:
//
// The identified file does not exist in the smart card.
#endif

#ifndef SCARD_E_ICC_CREATEORDER
#define SCARD_E_ICC_CREATEORDER						((DWORD)0x80100021L)
//
// MessageId: SCARD_E_ICC_CREATEORDER
//
// MessageText:
//
// The requested order of object creation is not supported.
#endif

#ifndef SCARD_E_ICC_INSTALLATION
#define SCARD_E_ICC_INSTALLATION					((DWORD)0x80100020L)
//
// MessageId: SCARD_E_ICC_INSTALLATION
//
// MessageText:
//
// No Primary Provider can be found for the smart card.
#endif

#endif //SCARDDEFS_H