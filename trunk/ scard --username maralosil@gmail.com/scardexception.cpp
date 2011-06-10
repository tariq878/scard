#include <winscard.h>
#include "scardexception.h"


SCardException::SCardException(long id) 
	: _id(id)
{}
	
char* SCardException:: what() {

	/*
	 * http://msdn.microsoft.com/en-us/library/aa374738(v=vs.85).aspx#smart_card_return_values
	 *
	 */

	switch(_id){

		case SCARD_F_INTERNAL_ERROR:
			return "SCardException: An internal consistency check failed.";

		case SCARD_E_INVALID_HANDLE:
			return "SCardException: The supplied handle was not valid.";

		case SCARD_E_INVALID_TARGET:
			return "SCardException: Registry startup information is missing or not valid.";

		case SCARD_F_WAITED_TOO_LONG:
			return "SCardException: An internal consistency timer has expired.";

		case SCARD_E_INSUFFICIENT_BUFFER:
			return "SCardException: The data buffer for returned data is too small for the returned data.";

		case SCARD_E_TIMEOUT:
			return "SCardException: The user-specified time-out value has expired.";

		case SCARD_E_SHARING_VIOLATION:
			return "SCardException: The smart card cannot be accessed because of other outstanding connections.";

		case SCARD_E_NO_SMARTCARD:
			return "SCardException: The operation requires a smart card, but no smart card is currently in the device.";

		case SCARD_E_UNKNOWN_CARD:
			return "SCardException: The specified smart card name is not recognized.";

		case SCARD_E_PROTO_MISMATCH:
			return "SCardException: The requested protocols are incompatible with the protocol currently in use with the card.";

		case SCARD_E_NOT_READY:
			return "SCardException: The reader or card is not ready to accept commands.";

		case SCARD_E_SYSTEM_CANCELLED:
			return "SCardException: The action was canceled by the system, presumably to log off or shut down.";

		case SCARD_F_COMM_ERROR:
			return "SCardException: An internal communications error has been detected.";

		case SCARD_F_UNKNOWN_ERROR:
			return "SCardException: An internal error has been detected, but the source is unknown.";

		case SCARD_E_INVALID_ATR:
			return "SCardException: An ATR string obtained from the registry is not a valid ATR string.";

		case SCARD_E_READER_UNAVAILABLE:
			return "SCardException: The specified reader is not currently available for use.";

		case SCARD_P_SHUTDOWN:
			return "SCardException: The operation has been aborted to allow the server application to exit.";

		case SCARD_E_PCI_TOO_SMALL:
			return "SCardException: The PCI receive buffer was too small.";

		case SCARD_E_READER_UNSUPPORTED:
			return "SCardException: The reader driver does not meet minimal requirements for support.";

		case SCARD_E_CARD_UNSUPPORTED:
			return "SCardException: The smart card does not meet minimal requirements for support.";

		case SCARD_E_SERVICE_STOPPED:
			return "SCardException: The smart card resource manager has shut down.";

		case SCARD_W_UNSUPPORTED_CARD:
			return "SCardException: The reader cannot communicate with the card, due to ATR string configuration conflicts.";

		case SCARD_W_UNRESPONSIVE_CARD:
			return "SCardException: The smart card is not responding to a reset.";

		case SCARD_W_UNPOWERED_CARD:
			return "SCardException: Power has been removed from the smart card, so that further communication is not possible.";

		case SCARD_W_RESET_CARD:
			return "SCardException: The smart card was reset.";

		case SCARD_W_REMOVED_CARD:
			return "SCardException: The smart card has been removed, so further communication is not possible.";


		default:
			return "SCardException: Unknown error.";

	}
		
}

	
