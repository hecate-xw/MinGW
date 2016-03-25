/**
 * @file mgm.h
 * Copyright 2012, 2013 MinGW.org project
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef _MGM_H
#define _MGM_H
#pragma GCC system_header
#include <_mingw.h>

#ifdef __cplusplus
extern "C" {
#endif

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)
#define MGM_JOIN_STATE_FLAG 0x00000001
#define MGM_FORWARD_STATE_FLAG 0x00000002
#define MGM_MFE_STATS_0 0x00000001
#define MGM_MFE_STATS_1 0x00000002
typedef enum _MGM_ENUM_TYPES {
	ANY_SOURCE=0,
	ALL_SOURCES
} MGM_ENUM_TYPES;
typedef struct _MGM_IF_ENTRY {
	DWORD dwIfIndex;
	DWORD dwIfNextHopAddr;
	BOOL bIGMP;
	BOOL bIsEnabled;
} MGM_IF_ENTRY,*PMGM_IF_ENTRY;
typedef DWORD(CALLBACK *PMGM_RPF_CALLBACK)(DWORD,DWORD,DWORD,DWORD,PDWORD,PDWORD,PDWORD,DWORD,PBYTE,PBYTE);
typedef DWORD(CALLBACK *PMGM_CREATION_ALERT_CALLBACK)(DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,PMGM_IF_ENTRY);
typedef DWORD(CALLBACK *PMGM_PRUNE_ALERT_CALLBACK)(DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,BOOL,PDWORD);
typedef DWORD(CALLBACK *PMGM_JOIN_ALERT_CALLBACK)(DWORD,DWORD,DWORD,DWORD,BOOL);
typedef DWORD(CALLBACK *PMGM_WRONG_IF_CALLBACK)(DWORD,DWORD,DWORD,DWORD,DWORD,PBYTE);
typedef DWORD(CALLBACK *PMGM_LOCAL_JOIN_CALLBACK)(DWORD,DWORD,DWORD,DWORD,DWORD,DWORD);
typedef DWORD(CALLBACK *PMGM_LOCAL_LEAVE_CALLBACK)(DWORD,DWORD,DWORD,DWORD,DWORD,DWORD);
typedef DWORD(CALLBACK *PMGM_DISABLE_IGMP_CALLBACK)(DWORD,DWORD);
typedef DWORD(CALLBACK *PMGM_ENABLE_IGMP_CALLBACK)(DWORD,DWORD);
typedef struct _ROUTING_PROTOCOL_CONFIG {
	DWORD dwCallbackFlags;
	PMGM_RPF_CALLBACK pfnRpfCallback;
	PMGM_CREATION_ALERT_CALLBACK pfnCreationAlertCallback;
	PMGM_PRUNE_ALERT_CALLBACK pfnPruneAlertCallback;
	PMGM_JOIN_ALERT_CALLBACK pfnJoinAlertCallback;
	PMGM_WRONG_IF_CALLBACK pfnWrongIfCallback;
	PMGM_LOCAL_JOIN_CALLBACK pfnLocalJoinCallback;
	PMGM_LOCAL_LEAVE_CALLBACK pfnLocalLeaveCallback;
	PMGM_DISABLE_IGMP_CALLBACK pfnDisableIgmpCallback;
	PMGM_ENABLE_IGMP_CALLBACK pfnEnableIgmpCallback;
} ROUTING_PROTOCOL_CONFIG,*PROUTING_PROTOCOL_CONFIG;
typedef struct _SOURCE_GROUP_ENTRY {
	DWORD dwSourceAddr;
	DWORD dwSourceMask;
	DWORD dwGroupAddr;
	DWORD dwGroupMask;
} SOURCE_GROUP_ENTRY,*PSOURCE_GROUP_ENTRY;
DWORD WINAPI MgmAddGroupMembershipEntry(HANDLE,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD);
DWORD WINAPI MgmDeleteGroupMembershipEntry(HANDLE,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD);
DWORD WINAPI MgmDeRegisterMProtocol(HANDLE);
DWORD WINAPI MgmGetFirstMfe(PDWORD,PBYTE,PDWORD);
DWORD WINAPI MgmGetFirstMfeStats(PDWORD,PBYTE,PDWORD,DWORD);
DWORD WINAPI MgmGetMfe(PMIB_IPMCAST_MFE,PDWORD,PBYTE);
DWORD WINAPI MgmGetMfeStats(PMIB_IPMCAST_MFE,PDWORD,PBYTE,DWORD);
DWORD WINAPI MgmGetNextMfe(PMIB_IPMCAST_MFE,PDWORD,PBYTE,PDWORD);
DWORD WINAPI MgmGetNextMfeStats(PMIB_IPMCAST_MFE,PDWORD,PBYTE,PDWORD,DWORD);
DWORD WINAPI MgmGetProtocolOnInterface(DWORD,DWORD,PDWORD,PDWORD);
DWORD WINAPI MgmGroupEnumerationEnd(HANDLE);
DWORD WINAPI MgmGroupEnumerationGetNext(HANDLE,PDWORD,PBYTE,PDWORD);
DWORD WINAPI MgmGroupEnumerationStart(HANDLE,MGM_ENUM_TYPES,HANDLE*);
DWORD WINAPI MgmRegisterMProtocol(PROUTING_PROTOCOL_CONFIG,DWORD,DWORD,HANDLE*);
DWORD WINAPI MgmReleaseInterfaceOwnership(HANDLE,DWORD,DWORD);
DWORD WINAPI MgmSetMfe(HANDLE,PMIB_IPMCAST_MFE);
DWORD WINAPI MgmTakeInterfaceOwnership(HANDLE,DWORD,DWORD);
#endif /* _WIN32_WINNT >= _WIN32_WINNT_WIN2K */

#ifdef __cplusplus
}
#endif

#endif
