//
//  APITwitter.swift
//  d04
//
//  Created by Sergio VELHINHO on 6/15/17.
//  Copyright © 2017 Sergio VELHINHO. All rights reserved.
//

import Foundation

protocol APITwitterDelegate : class {
    func manageTweets(tweet : [Tweet])
    func errorTweets(error : NSError)
}
