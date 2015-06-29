/*

 Copyright (c) 2014, Hookflash Inc. / Hookflash Inc.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of the FreeBSD Project.
 
 */

#include <ortc/internal/ortc_ISecureTransport.h>
#include <ortc/internal/ortc_DTLSTransport.h>
#include <ortc/internal/ortc_SRTPSDESTransport.h>
#include <ortc/internal/platform.h>

//#include <openpeer/services/IHelper.h>
//#include <openpeer/services/IHTTP.h>
//
//#include <zsLib/Stringize.h>
//#include <zsLib/Log.h>
//#include <zsLib/XML.h>
//
//#include <cryptopp/sha.h>

namespace ortc { ZS_DECLARE_SUBSYSTEM(ortclib) }

namespace ortc
{
//  ZS_DECLARE_TYPEDEF_PTR(openpeer::services::IHelper, UseServicesHelper)
//  ZS_DECLARE_TYPEDEF_PTR(openpeer::services::IHTTP, UseHTTP)
//
//  typedef openpeer::services::Hasher<CryptoPP::SHA1> SHA1Hasher;

  namespace internal
  {
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark (helpers)
    #pragma mark

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark ISecureTransportForRTPSender
    #pragma mark
    
    //-------------------------------------------------------------------------
    ElementPtr ISecureTransportForRTPSender::toDebug(ForRTPSenderPtr transport)
    {
      if (!transport) return ElementPtr();

      {
        auto pThis = DTLSTransport::convert(transport);
        if (pThis) return DTLSTransport::toDebug(pThis);
      }

      {
        auto pThis = SRTPSDESTransport::convert(transport);
        if (pThis) return SRTPSDESTransport::toDebug(pThis);
      }
      return ElementPtr();
    }
    
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark ISecureTransportForSRTPTransport
    #pragma mark
    
    //-------------------------------------------------------------------------
    ElementPtr ISecureTransportForSRTPTransport::toDebug(ForSRTPPtr transport)
    {
      if (!transport) return ElementPtr();

      {
        auto pThis = DTLSTransport::convert(transport);
        if (pThis) return DTLSTransport::toDebug(pThis);
      }

      {
        auto pThis = SRTPSDESTransport::convert(transport);
        if (pThis) return SRTPSDESTransport::toDebug(pThis);
      }
      return ElementPtr();
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark ISecureTransportForICETransport
    #pragma mark
    
    //-------------------------------------------------------------------------
    ElementPtr ISecureTransportForICETransport::toDebug(ForICETransportPtr transport)
    {
      if (!transport) return ElementPtr();

      {
        auto pThis = DTLSTransport::convert(transport);
        if (pThis) return DTLSTransport::toDebug(pThis);
      }

      {
        auto pThis = SRTPSDESTransport::convert(transport);
        if (pThis) return SRTPSDESTransport::toDebug(pThis);
      }
      return ElementPtr();
    }
 
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    #pragma mark
    #pragma mark ISecureTransportForRTPListener
    #pragma mark

    //-------------------------------------------------------------------------
    ElementPtr ISecureTransportForRTPListener::toDebug(ForRTPListenerPtr transport)
    {
      if (!transport) return ElementPtr();

      {
        auto pThis = DTLSTransport::convert(transport);
        if (pThis) return DTLSTransport::toDebug(pThis);
      }

      {
        auto pThis = SRTPSDESTransport::convert(transport);
        if (pThis) return SRTPSDESTransport::toDebug(pThis);
      }
      return ElementPtr();
    }

    //-------------------------------------------------------------------------
    ISecureTransportForRTPListener::ForRTPListenerPtr ISecureTransportForRTPListener::convert(IRTPTransportPtr transport)
    {
      if (!transport) return ForRTPListenerPtr();
      return ZS_DYNAMIC_PTR_CAST(ForRTPListener, transport);
    }

  }

}
