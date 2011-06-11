#include <winscard.h>
#include <sstream>
#include <iomanip>
#include "scardexception.h"
#include "scarddefs.h"

SCardException::SCardException(long id) 
	: _id(id)
{}

long SCardException::getId() {

	return _id;
}

String SCardException::what() {

	std::stringstream err;

	err << "ScardException " << std::setfill('0') 
		<< std::setw(8) << std::hex << getId() << ": " << getMessage();
	
	return err.str();
}

char* SCardException:: getMessage() {

	switch(_id){

		case SCARD_F_INTERNAL_ERROR:
			return "An internal consistency check failed.";

		case SCARD_E_INVALID_HANDLE:
			return "The supplied handle was not valid.";

		case SCARD_E_INVALID_TARGET:
			return "Registry startup information is missing or not valid.";

		case SCARD_F_WAITED_TOO_LONG:
			return "An internal consistency timer has expired.";

		case SCARD_E_INSUFFICIENT_BUFFER:
			return "The data buffer for returned data is too small for the returned data.";

		case SCARD_E_TIMEOUT:
			return "The user-specified time-out value has expired.";

		case SCARD_E_SHARING_VIOLATION:
			return "The smart card cannot be accessed because of other outstanding connections.";

		case SCARD_E_NO_SMARTCARD:
			return "The operation requires a smart card, but no smart card is currently in the device.";

		case SCARD_E_UNKNOWN_CARD:
			return "The specified smart card name is not recognized.";

		case SCARD_E_PROTO_MISMATCH:
			return "The requested protocols are incompatible with the protocol currently in use with the card.";

		case SCARD_E_NOT_READY:
			return "The reader or card is not ready to accept commands.";

		case SCARD_E_SYSTEM_CANCELLED:
			return "The action was canceled by the system, presumably to log off or shut down.";

		case SCARD_F_COMM_ERROR:
			return "An internal communications error has been detected.";

		case SCARD_F_UNKNOWN_ERROR:
			return "An internal error has been detected, but the source is unknown.";

		case SCARD_E_INVALID_ATR:
			return "An ATR string obtained from the registry is not a valid ATR string.";

		case SCARD_E_READER_UNAVAILABLE:
			return "The specified reader is not currently available for use.";

		case SCARD_P_SHUTDOWN:
			return "The operation has been aborted to allow the server application to exit.";

		case SCARD_E_PCI_TOO_SMALL:
			return "The PCI receive buffer was too small.";

		case SCARD_E_READER_UNSUPPORTED:
			return "The reader driver does not meet minimal requirements for support.";

		case SCARD_E_CARD_UNSUPPORTED:
			return "The smart card does not meet minimal requirements for support.";

		case SCARD_E_SERVICE_STOPPED:
			return "The smart card resource manager has shut down.";

		case SCARD_W_UNSUPPORTED_CARD:
			return "The reader cannot communicate with the card, due to ATR string configuration conflicts.";

		case SCARD_W_UNRESPONSIVE_CARD:
			return "The smart card is not responding to a reset.";

		case SCARD_W_UNPOWERED_CARD:
			return "Power has been removed from the smart card, so that further communication is not possible.";

		case SCARD_W_RESET_CARD:
			return "The smart card was reset.";

		case SCARD_W_REMOVED_CARD:
			return "The smart card has been removed, so further communication is not possible.";

		case SCARD_E_NO_READERS_AVAILABLE:
			return "Cannot find a smart card reader.";

		case SCARD_E_NO_RESRC_MNGR_RUNNING:
			return "The Smart card resource manager is not running.";

		default:
			return "Unknown error.";

	}
		
}
