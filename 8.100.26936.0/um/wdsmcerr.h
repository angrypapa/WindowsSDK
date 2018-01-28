//
//
// Copyright (c) 2006 Microsoft Corporation
//
// ADDING AND REMOVING MESSAGES
//
// Note that the MessageId is actually broken up into two parts.  The
// high 4 bits is actually an error level indicating the severity of
// the error.  The rest of the bit number indicates the actual event
// message id.  The error level can be used to filter out event
// messages that you don't want logged all the time, unless the
// administrator is actively diagnosing something.  Also note the
// message id's are limited to a 16-bit number.
//
// The messages in this file are explicitly numbered. Do not renumber
// existing messages so as to make space to add your message.
// You should always add you message in the end of the file.
// The reason is that it often desirable to be able to read an event
// log with a message file that is from a different build, so renumbering
// existing messages should be avoided.
//
// If you want to remove a message, do NOT simply delete it from the file.
// Instead change its symbolic name to BIGLOG_UNUSED_xxx (where xxx is a
// sequential number just used to uniquify the names) and its text to
//  "Unused message".
//
// If you want to set the log level of the message, you need to OR the
// message ID with the following constants, to get log level of 0, 1, 2, 3
// 0x0000 , 0x4000, 0x8000, 0xc000
//
// For example:
//     MessageId=0x8100
//     Facility=MyFacility
//     Severity=Error
//     SymbolicName=ERROR_ID_100
//     Language=English
//     This is the text for error ID 0x101, with error level 8
//     .
//     MessageId=0x4101
//     Facility=MyFacility
//     Severity=Error
//     SymbolicName=ERROR_ID_101
//     Language=English
//     This is the text for error ID 0x101, with error level 1
//     .
//     .
//     MessageId=0x10000
//     Facility=MyFacility
//     Severity=Error
//     SymbolicName=ERROR_ID_10000
//     Language=English
//     DON'T DO THIS!!!  Message ID is > 0xFFFF.  This won't EVER work
//     .
//
// IMPORTANT NOTES
//
// NOTE THAT YOU MUST NOT DELETE OR RE-USE EVENTS THAT WERE MEANINGFUL IN
// PREVIOUSLY RELEASED VERSIONS OF THE PRODUCT.  Why?  Consider an app running
// on Win2k+1 that scans the event logs of all DCs (Win2k and Win2k+1) in an
// enterprise.  The scanner should be able to retrieve the text asociated
// with the Win2k event on the Win2k+1 box (since the event log does not
// provide this service -- text must always be looked up locally).  Also
// consider that watchdog tools often cue off of certain event IDs appearing
// in the event log (e.g., to page an admin when something particularly bad
// happens), so you don't want event 893 to mean one thing on Win2k and
// something completely different on Win2k+1.
//
// By the same token, YOU MUST NOT CHANGE THE ORDER OF INSERTION STRINGS OF
// EVENTS THAT WERE MEANINGFUL IN PREVIOUSLY RELEASED VERSIONS OF THE PRODUCT.
// It's okay to add new insertion strings to existing event log messages (they
// just won't be filled in when looking at the event generated by an older
// program), just add them at the end.  (E.g., if %1 %2 and %3 are already used,
// add new insertion strings at %4, *don't* put the new one as %2 and bump
// the old %2 to %3 and the old %3 to %4.)  Whether an insertion string is
// %1 or %4 or whatever of course doesn't restrict where it can be placed in
// the message text, it only provides a mapping to the order of parameters
// given to LogEvent.
//
// To add a new message, first see if there is an existing unused message
// that you can recycle.  If so, do so.  If no more unused messages remain,
// then you must be sure to add new messages only at the very end of the
// file.
// 
// Naming Convention:
//
// For error codes (which are not logged to event log)
//
//     <Facility>_<Type>_<Error>
//
// For errors that are logged as events in event log:
//
//     EVT_<Facility>_<Type>_<Error>
//
// Dev Note:
//     If you add new facilities here, remember to update the registry setup
//     for event logging in the manifest to correctly reflect the new category
//     count.
//
// Define the severities
//
// Define the facility names
//
//
// Category Names Used for Event Logging
//
//
// These message id's are names for categories, which are equivalent to
// to facilities - 0x100.  LogEvent extracts the facility from the HRESULT,
// and logs that as the Category.  These message IDs allow that category
// to appear as the textual facility name in the event viewer
//
//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//
#define FACILITY_WDSMCSERVER             0x121
#define FACILITY_WDSMCCLIENT             0x122


//
// Define the severity codes
//
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: WDSMCSERVER_CATEGORY
//
// MessageText:
//
// WDS Multicast Server
//
#define WDSMCSERVER_CATEGORY             ((HRESULT)0x00000001L)

//
// MessageId: WDSMCCLIENT_CATEGORY
//
// MessageText:
//
// WDS Multicast Client
//
#define WDSMCCLIENT_CATEGORY             ((HRESULT)0x00000002L)

///////////////////////////////////////////////////////////////////
//
// WDS Multicast Server Facility Error Codes.
//
///////////////////////////////////////////////////////////////////
//
// MessageId: WDSMCS_E_SESSION_SHUTDOWN_IN_PROGRESS
//
// MessageText:
//
// The request for content was rejected because shutdown is in progress for 
// the specified session.
//
#define WDSMCS_E_SESSION_SHUTDOWN_IN_PROGRESS ((HRESULT)0xC1210100L)

//
// MessageId: WDSMCS_E_REQCALLBACKS_NOT_REG
//
// MessageText:
//
// The Content Provider did not register required callbacks.
//
#define WDSMCS_E_REQCALLBACKS_NOT_REG    ((HRESULT)0xC1210101L)

//
// MessageId: WDSMCS_E_INCOMPATIBLE_VERSION
//
// MessageText:
//
// The supported version reported by Content Provider is incompatible.
//
#define WDSMCS_E_INCOMPATIBLE_VERSION    ((HRESULT)0xC1210102L)

//
// MessageId: WDSMCS_E_CONTENT_NOT_FOUND
//
// MessageText:
//
// The specified content was not found.
//
#define WDSMCS_E_CONTENT_NOT_FOUND       ((HRESULT)0xC1210103L)

//
// MessageId: WDSMCS_E_CLIENT_NOT_FOUND
//
// MessageText:
//
// The specified client was not found.
//
#define WDSMCS_E_CLIENT_NOT_FOUND        ((HRESULT)0xC1210104L)

//
// MessageId: WDSMCS_E_NAMESPACE_NOT_FOUND
//
// MessageText:
//
// The specified namespace was not found.
//
#define WDSMCS_E_NAMESPACE_NOT_FOUND     ((HRESULT)0xC1210105L)

//
// MessageId: WDSMCS_E_CONTENT_PROVIDER_NOT_FOUND
//
// MessageText:
//
// The specified content provider was not found.
//
#define WDSMCS_E_CONTENT_PROVIDER_NOT_FOUND ((HRESULT)0xC1210106L)

//
// MessageId: WDSMCS_E_NAMESPACE_ALREADY_EXISTS
//
// MessageText:
//
// The specified namespace already exists.
//
#define WDSMCS_E_NAMESPACE_ALREADY_EXISTS ((HRESULT)0xC1210107L)

//
// MessageId: WDSMCS_E_NAMESPACE_SHUTDOWN_IN_PROGRESS
//
// MessageText:
//
// The namespace is pending closure due to inactivity.
//
#define WDSMCS_E_NAMESPACE_SHUTDOWN_IN_PROGRESS ((HRESULT)0xC1210108L)

//
// MessageId: WDSMCS_E_NAMESPACE_ALREADY_STARTED
//
// MessageText:
//
// The namespace has already started.
//
#define WDSMCS_E_NAMESPACE_ALREADY_STARTED ((HRESULT)0xC1210109L)

//
// MessageId: WDSMCS_E_NS_START_FAILED_NO_CLIENTS
//
// MessageText:
//
// The namespace cannot be started because there are no clients in the namespace.
//
#define WDSMCS_E_NS_START_FAILED_NO_CLIENTS ((HRESULT)0xC121010AL)

//
// MessageId: WDSMCS_E_START_TIME_IN_PAST
//
// MessageText:
//
// The specified start time is in the past.
//
#define WDSMCS_E_START_TIME_IN_PAST      ((HRESULT)0xC121010BL)

//
// MessageId: WDSMCS_E_PACKET_NOT_HASHED
//
// MessageText:
//
// A packet was received without a hash.
//
#define WDSMCS_E_PACKET_NOT_HASHED       ((HRESULT)0xC121010CL)

//
// MessageId: WDSMCS_E_PACKET_NOT_SIGNED
//
// MessageText:
//
// A packet was received without a signature.
//
#define WDSMCS_E_PACKET_NOT_SIGNED       ((HRESULT)0xC121010DL)

//
// MessageId: WDSMCS_E_PACKET_HAS_SECURITY
//
// MessageText:
//
// A signed or hashed packet was received.
//
#define WDSMCS_E_PACKET_HAS_SECURITY     ((HRESULT)0xC121010EL)

//
// MessageId: WDSMCS_E_PACKET_NOT_CHECKSUMED
//
// MessageText:
//
// A packet was received without a checksum.
//
#define WDSMCS_E_PACKET_NOT_CHECKSUMED   ((HRESULT)0xC121010FL)

//
// MessageId: WDSMCS_E_CLIENT_DOESNOT_SUPPORT_SECURITY_MODE
//
// MessageText:
//
// The client does not support the required security mode.
//
#define WDSMCS_E_CLIENT_DOESNOT_SUPPORT_SECURITY_MODE ((HRESULT)0xC1210110L)

///////////////////////////////////////////////////////////////////
//
// WDS Multicast Server Facility Event Log Messages.
//
///////////////////////////////////////////////////////////////////
//
// MessageId: EVT_WDSMCS_S_PARAMETERS_READ
//
// MessageText:
//
// The Windows Deployment Services multicast server successfully read its configuration
// settings. The Windows Deployment Services multicast server will now process incoming 
// client requests.
//
#define EVT_WDSMCS_S_PARAMETERS_READ     ((HRESULT)0x41210200L)

//
// MessageId: EVT_WDSMCS_E_PARAMETERS_READ_FAILED
//
// MessageText:
//
// An error occurred while trying to read the configuration information. The 
// Windows Deployment Services multicast server will not process incoming 
// client requests. %n
// %n
// Error Information: %1 %n
//
#define EVT_WDSMCS_E_PARAMETERS_READ_FAILED ((HRESULT)0xC1210201L)

//
// MessageId: EVT_WDSMCS_E_DUPLICATE_MULTICAST_ADDR
//
// MessageText:
//
// The multicast IP address %1 is being used by another Windows Deployment Services 
// server, which has IP %2. Use the Windows Deployment Services management tools to 
// configure your multicast IP address range to avoid this multicast IP address. If 
// you allow this overlap to continue, your network usage will be increased.
//
#define EVT_WDSMCS_E_DUPLICATE_MULTICAST_ADDR ((HRESULT)0xC1210202L)

//
// MessageId: EVT_WDSMCS_E_NON_WDS_DUPLICATE_MULTICAST_ADDR
//
// MessageText:
//
// The multicast IP address %1 is being used by another multicast server, which has 
// IP %2. Use the Windows Deployment Services management tools to configure your 
// multicast IP address range to avoid this multicast IP address. If you allow this
// overlap to continue, your network usage will be increased.
//
#define EVT_WDSMCS_E_NON_WDS_DUPLICATE_MULTICAST_ADDR ((HRESULT)0xC1210203L)

//---------------------------------------------------------- Content Providers.
//
// MessageId: EVT_WDSMCS_E_CP_DLL_LOAD_FAILED
//
// MessageText:
//
// An error occurred while trying to load the module %1 for Content Provider %2. %n
// %n
// Error Information: %3 %n
//
#define EVT_WDSMCS_E_CP_DLL_LOAD_FAILED  ((HRESULT)0xC1210250L)

//
// MessageId: EVT_WDSMCS_E_CP_INIT_FUNC_MISSING
//
// MessageText:
//
// The module %1 for Content Provider %2 does not export the initialization 
// function %3. %n
// %n
// Error Information: %4 %n
//
#define EVT_WDSMCS_E_CP_INIT_FUNC_MISSING ((HRESULT)0xC1210251L)

//
// MessageId: EVT_WDSMCS_E_CP_INIT_FUNC_FAILED
//
// MessageText:
//
// The Content Provider %1 loaded from %2 failed to initialize. %n
// %n
// Error Information: %3 %n
//
#define EVT_WDSMCS_E_CP_INIT_FUNC_FAILED ((HRESULT)0xC1210252L)

//
// MessageId: EVT_WDSMCS_E_CP_INCOMPATIBLE_SERVER_VERSION
//
// MessageText:
//
// The Content Provider %1 is incompatible with this version of Windows Deployment
// Multicast Server. %n
//
#define EVT_WDSMCS_E_CP_INCOMPATIBLE_SERVER_VERSION ((HRESULT)0xC1210253L)

//
// MessageId: EVT_WDSMCS_E_CP_CALLBACKS_NOT_REG
//
// MessageText:
//
// The Content Provider %1 did not register required callbacks during its 
// initialization. %n
//
#define EVT_WDSMCS_E_CP_CALLBACKS_NOT_REG ((HRESULT)0xC1210254L)

//
// MessageId: EVT_WDSMCS_E_CP_SHUTDOWN_FUNC_FAILED
//
// MessageText:
//
// The shutdown function for Content Provider %1 failed. %n
// %n
// Error Information: %2 %n
//
#define EVT_WDSMCS_E_CP_SHUTDOWN_FUNC_FAILED ((HRESULT)0xC1210255L)

//
// MessageId: EVT_WDSMCS_E_CP_MEMORY_LEAK
//
// MessageText:
//
// The Content Provider %1 did not release %2 memory allocation(s) after its 
// shutdown function has successfully returned.
//
#define EVT_WDSMCS_E_CP_MEMORY_LEAK      ((HRESULT)0xC1210256L)

//
// MessageId: EVT_WDSMCS_E_CP_OPEN_INSTANCE_FAILED
//
// MessageText:
//
// The Content Provider %1 returned an error while trying to open a new instance. %n
// %n
// Configuration: %2 %n
// Error Information: %3 %n
//
#define EVT_WDSMCS_E_CP_OPEN_INSTANCE_FAILED ((HRESULT)0xC1210257L)

//
// MessageId: EVT_WDSMCS_E_CP_CLOSE_INSTANCE_FAILED
//
// MessageText:
//
// The Content Provider %1 returned an error while trying to close an instance. %n
// %n
// Error Information: %2 %n
//
#define EVT_WDSMCS_E_CP_CLOSE_INSTANCE_FAILED ((HRESULT)0xC1210258L)

//
// MessageId: EVT_WDSMCS_E_CP_OPEN_CONTENT_FAILED
//
// MessageText:
//
// The Content Provider %1 returned an error while trying to open content %2. %n
// %n
// Error Information: %3 %n
//
#define EVT_WDSMCS_E_CP_OPEN_CONTENT_FAILED ((HRESULT)0xC1210259L)

//
// MessageId: EVT_WDSMCS_W_CP_DLL_LOAD_FAILED_NOT_CRITICAL
//
// MessageText:
//
// The Content Provider %1 failed to initialize. The provider is marked as non-critical.
// WDS Multicast server will continue to start.%n
// %n
// Error Information: %2 %n
//
#define EVT_WDSMCS_W_CP_DLL_LOAD_FAILED_NOT_CRITICAL ((HRESULT)0x8121025AL)

//
// MessageId: EVT_WDSMCS_E_CP_DLL_LOAD_FAILED_CRITICAL
//
// MessageText:
//
// The Content Provider %1 failed to initialize. The provider is marked as critical.
// WDS Multicast server will fail to start.%n
// %n
// Error Information: %2 %n
//
#define EVT_WDSMCS_E_CP_DLL_LOAD_FAILED_CRITICAL ((HRESULT)0xC121025BL)

//------------------------------------------------------------------ Namespace.
//
// MessageId: EVT_WDSMCS_E_NSREG_START_TIME_IN_PAST
//
// MessageText:
//
// The ScheduledCast namespace %1 using content provider %2 could not be registered 
// as it starts in the past. The namespace has been removed from the namespace 
// store. %n
// %n
// Error Information: %3 %n
//
#define EVT_WDSMCS_E_NSREG_START_TIME_IN_PAST ((HRESULT)0xC1210300L)

//
// MessageId: EVT_WDSMCS_E_NSREG_CONTENT_PROVIDER_NOT_REG
//
// MessageText:
//
// The namespace %1 using content provider %2 could not be registered because 
// the content provider is not registered. The namespace has been removed from 
// the namespace store. %n
// %n
// Error Information: %3 %n
//
#define EVT_WDSMCS_E_NSREG_CONTENT_PROVIDER_NOT_REG ((HRESULT)0xC1210301L)

//
// MessageId: EVT_WDSMCS_E_NSREG_NAMESPACE_EXISTS
//
// MessageText:
//
// The namespace %1 using content provider %2 could not be registered because a 
// namespace by that name already exists. The namespace has been removed from the 
// namespace store. %n
// %n
// Error Information: %3 %n
//
#define EVT_WDSMCS_E_NSREG_NAMESPACE_EXISTS ((HRESULT)0xC1210302L)

//
// MessageId: EVT_WDSMCS_E_NSREG_FAILURE
//
// MessageText:
//
// The namespace %1 using content provider %2 could not be registered due to an 
// unknown error. %n
// %n
// Error Information: %3 %n
//
#define EVT_WDSMCS_E_NSREG_FAILURE       ((HRESULT)0xC1210303L)

///////////////////////////////////////////////////////////////////
//
// WDS Multicast Client Facility Error Codes.
//
///////////////////////////////////////////////////////////////////
//
// MessageId: WDSTPC_E_CALLBACKS_NOT_REG
//
// MessageText:
//
// The required callbacks were not registered.
//
#define WDSTPC_E_CALLBACKS_NOT_REG       ((HRESULT)0xC1220300L)

//
// MessageId: WDSTPC_E_ALREADY_COMPLETED
//
// MessageText:
//
// The session has already completed the download. 
//
#define WDSTPC_E_ALREADY_COMPLETED       ((HRESULT)0xC1220301L)

//
// MessageId: WDSTPC_E_ALREADY_IN_PROGRESS
//
// MessageText:
//
// The download is already in progress.
//
#define WDSTPC_E_ALREADY_IN_PROGRESS     ((HRESULT)0xC1220302L)

//
// MessageId: WDSTPC_E_UNKNOWN_ERROR
//
// MessageText:
//
// An unknown error occurred.
//
#define WDSTPC_E_UNKNOWN_ERROR           ((HRESULT)0xC1220303L)

//
// MessageId: WDSTPC_E_NOT_INITIALIZED
//
// MessageText:
//
// WDS Multicast Client not initialized.
//
#define WDSTPC_E_NOT_INITIALIZED         ((HRESULT)0xC1220304L)

//
// MessageId: WDSTPC_E_KICKED_POLICY_NOT_MET
//
// MessageText:
//
// The client did not meet the policy requirements set by the administrator and was
// kicked from the session.
//
#define WDSTPC_E_KICKED_POLICY_NOT_MET   ((HRESULT)0xC1220305L)

//
// MessageId: WDSTPC_E_KICKED_FALLBACK
//
// MessageText:
//
// The client was disconnected by the administrator. The server requested that the client 
// use another method to obtain the contents.
//
#define WDSTPC_E_KICKED_FALLBACK         ((HRESULT)0xC1220306L)

//
// MessageId: WDSTPC_E_KICKED_FAIL
//
// MessageText:
//
// The client was disconnected by the administrator.
//
#define WDSTPC_E_KICKED_FAIL             ((HRESULT)0xC1220307L)

//
// MessageId: WDSTPC_E_KICKED_UNKNOWN
//
// MessageText:
//
// The client was disconnected by the administrator. An unknown reason was specified
// for disconnecting the client from the session.
//
#define WDSTPC_E_KICKED_UNKNOWN          ((HRESULT)0xC1220308L)

//
// MessageId: WDSTPC_E_MULTISTREAM_NOT_ENABLED
//
// MessageText:
//
// Multistream support is not enabled.
//
#define WDSTPC_E_MULTISTREAM_NOT_ENABLED ((HRESULT)0xC1220309L)

//
// MessageId: WDSTPC_E_ALREADY_IN_LOWEST_SESSION
//
// MessageText:
//
// The specified client is already in the lowest multistream session.
//
#define WDSTPC_E_ALREADY_IN_LOWEST_SESSION ((HRESULT)0xC122030AL)

//
// MessageId: WDSTPC_E_CLIENT_DEMOTE_NOT_SUPPORTED
//
// MessageText:
//
// The specified client does not support demotion.
//
#define WDSTPC_E_CLIENT_DEMOTE_NOT_SUPPORTED ((HRESULT)0xC122030BL)

//
// MessageId: WDSTPC_E_NO_IP4_INTERFACE
//
// MessageText:
//
// No IPv4 interface available on the server.
//
#define WDSTPC_E_NO_IP4_INTERFACE        ((HRESULT)0xC122030CL)

//
// MessageId: WDSTPTC_E_WIM_APPLY_REQUIRES_REFERENCE_IMAGE
//
// MessageText:
//
// 
// The specified WIM file requires a reference WIM such as res.rwm in order to be applied.
//
#define WDSTPTC_E_WIM_APPLY_REQUIRES_REFERENCE_IMAGE ((HRESULT)0xC122030DL)

