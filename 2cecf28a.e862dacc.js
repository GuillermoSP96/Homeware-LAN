(window.webpackJsonp=window.webpackJsonp||[]).push([[7],{75:function(e,t,r){"use strict";r.r(t),r.d(t,"frontMatter",(function(){return a})),r.d(t,"metadata",(function(){return o})),r.d(t,"rightToc",(function(){return c})),r.d(t,"default",(function(){return l}));var i=r(3),n=(r(0),r(104));const a={id:"renew-ssl-certificate",title:"Renew the SSL certificate",sidebar_label:"SSL certificate",slug:"/renew-ssl-certificate"},o={unversionedId:"renew-ssl-certificate",id:"renew-ssl-certificate",isDocsHomePage:!1,title:"Renew the SSL certificate",description:"Remember that the SSL certificate that you have installed will be revoked 3 months after creation. When this happen renew it running Certbot again:",source:"@site/docs/renew-ssl-certificate.md",slug:"/renew-ssl-certificate",permalink:"/Homeware-LAN/docs/renew-ssl-certificate",editUrl:"https://github.com/facebook/docusaurus/edit/master/website/docs/renew-ssl-certificate.md",version:"current",sidebar_label:"SSL certificate",sidebar:"someSidebar",previous:{title:"Connecting hardware to Homeware",permalink:"/Homeware-LAN/docs/connecting-hardware"},next:{title:"Upgrade to v1.0.0",permalink:"/Homeware-LAN/docs/upgrade-to-v100"}},c=[],s={rightToc:c};function l({components:e,...t}){return Object(n.b)("wrapper",Object(i.a)({},s,t,{components:e,mdxType:"MDXLayout"}),Object(n.b)("p",null,"Remember that the SSL certificate that you have installed will be revoked 3 months after creation. When this happen renew it running Certbot again:"),Object(n.b)("pre",null,Object(n.b)("code",Object(i.a)({parentName:"pre"},{}),"sudo certbot --nginx\n")),Object(n.b)("p",null,"Make sure that the 80 WAN port is forwarding to the 80 port of the Raspberry Pi."),Object(n.b)("p",null,"You can find the revoke date using your web browser:"),Object(n.b)("ol",null,Object(n.b)("li",{parentName:"ol"},"Go to you Homeware panel."),Object(n.b)("li",{parentName:"ol"},"Click on the padlock that appear on the left side of the URL."),Object(n.b)("li",{parentName:"ol"},"Click on ",Object(n.b)("em",{parentName:"li"},"Certificate"),".")))}l.isMDXComponent=!0}}]);