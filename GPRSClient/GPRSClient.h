/*
 * GPRSClient.h
 *
 * Copyright (c) 2014 seeed technology inc.
 * Website    : www.seeed.cc
 * Author     : lawliet zou
 * Create Time: Feb 2014
 * Change Log :
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
 
#ifndef __GPRSCLIENT_H__
#define __GPRSCLIENT_H__

#include "GPRS.h"
#include "Client.h"

/** Interface using GPRS to connect to an IP-based network
 *
 */
class GPRSClient: public GPRS{

public:

    /** Constructor
     *  @param tx mbed pin to use for tx line of Serial interface
     *  @param rx mbed pin to use for rx line of Serial interface
     *  @param baudRate serial communicate baud rate
     *  @param apn name of the gateway for GPRS to connect to the network
     *  @param userName apn's username, usually is NULL
     *  @param passWord apn's password, usually is NULL
     */
    GPRSClient(int tx, int rx, int baudRate, const char* apn, const char* userName = NULL, const char *passWord = NULL);

    /** Initialize the interface(no connection at this point).
     *  @return 0 on success, a negative number on failure
     */
    int init();

    /** Connect to the network and get IP address
     *  @returns 0 on success, a negative number on failure
     */
    int join();

    /** Get IP address
     *  @returns ip address
     */
    char* getIPAddress();
    
    int connect(char* host, uint16_t port);
    
    int connect(IPAddress ip, uint16_t port);
        
    size_t write(char data);
    size_t write(char* buf, size_t length);
    int available();
    int read();
    int read(char* buf, size_t length);
    int peek();
    void flush();
    void stop();
    uint8_t connected();
   
private:
    int _socket_fd;
    char ip_string[20];
    bool ip_set;
};


#endif
