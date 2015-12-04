Pod::Spec.new do |s|

  s.name         = "BNGAPI"
  s.version      = "2.1"
  s.summary      = "Simple API client for interacting with Betfair API services."
  s.homepage     = "https://github.com/betfair/aping-ios-sdk"

  s.license      = { :type => "Apache 2", :file => 'LICENSE' }

  s.author       = { "Sean O Shea" => "oshea.ie@gmail.com" }

  s.source       = {
      :git => "https://github.com/betfair/aping-ios-sdk.git",
      :tag => "tags/2.1"
  }

  s.ios.deployment_target = '5.0'
  s.osx.deployment_target = '10.8'

  s.source_files = 'BNGAPI/BNGAPI/*.{h,m}', 'BNGAPI/BNGAPI/**/*.{h,m}'
  s.exclude_files = 'BNGAPI/BNGAPITests/'
  s.requires_arc = true

end
