/**
 *   GPStar Attenuator - Ghostbusters Proton Pack & Neutrona Wand.
 *   Copyright (C) 2023-2024 Michael Rajotte <michael.rajotte@gpstartechnologies.com>
 *                         & Dustin Grau <dustin.grau@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, see <https://www.gnu.org/licenses/>.
 *
 */

#pragma once

// Compress first via https://processing.compress-or-die.com/svg-process

const char EQUIP_svg[] PROGMEM = R"=====(
H4sIAAAAAAAAA6SayZIbxxGG736KjvG5m117lUNUhH3CwXPFYW4ISFTTniEVGrqp8NP7/7KwDIWG7JCDnEYja8/1zyx897r+NKwff/z6t8+/vn+Yh3lwLg0uzQ/Dry/Pn17fPyxfvvz8l3fvvn79On0N0+dffnrn53l+p3EP3/9pGL77afjw8fn5/cOfP3z48DC8fvnl8z9/1Df1OX8bv3784cvy/mHyNkJjfj58WYYf3j885jS5IU01L3kK5TVObpz8kKfkBz+VevRTdHprVY+Q1bOV69vex1c3zeqjHU9z5BFW16bsnscENdcp7ZyfcttXGp+1XBrb5N0+uymVV60XtPAYJ6+XGI681XGay8gwP8znz72vkw+L1t0XdVmC09fXcQqj77t1nre2+DAlbSuEUUfTpx/c06NLUxhcSNOctAetENV1iFPj9LmO0AZoTw/vfsujpAOWIZQpxV2ZJ7+KUHdGve39knSAIbYpxiHoxKM4UHah6pCrtjyXRWsVv7o4hcW7yeXnKY4hT3VjrjhPKQ1VrFxsghwkiWXk/d+3vV2eWhyapBl0qFhHiTQOaRYboniCRKpEG9LWWB1J8ptj37cGlymHIc9im9crwqkDtK3BcFt6G1hZR2rscJBqSW5iRBolqkGk7XUlPCeZBXox0NnIMLauVq7dGZrqNNfBRamUhs0BvZTWSExhTG1i2IxybPIq58kVDRZzdNI5IfswBrGpjMmUXtSIlmzuOrNNF7yUf7xyK8luRo81wcJyj11e8+vMoaGjZ0GFIUp8YdSOSkJ8DVHFjeFhNp2OUfbJ3oPtcggmYj95z9bDcGfrWlVyjmWKeTwzKA/iWmxwrQxnVm5pSSm2tHQ3ukMwu+xP81tjwP6Mko+jq7JdKHVU/+xP79Z6O3a4tqYjQ4c+mQ0drhNv7OoRToRB/qXYxCkP/cnE2sIsVfDdhJng9Jz7us4oWZ7HBvVHb5PNuopb2BjmUXIN8+l5RE8mFzllSaMsv8Wj3FJEn+WDahWL+WI2lA/mW+3R96ct6GhTWb3knzecQPFoxInpcoLys/3Zmc67N0oZtlv7c6N1+O+tp5k3uI4nvOiClB4fnM7HcpiBVBhKGu60jnda7d0a43ajPJG1Pr2IpT6NeNd8QHn5o5MbFYWC7f9KtgbIEpnf8POyIPkTJ5eAlOTK7MGomRGj/Js04G0L/1jDWp5epGxTOgRsxB42VIPzlOPwltz/iRye8Aaz1F8Db9d0d9d0/9eacCeJiWYyGW9nj/NYgoEf3tIval99X3IurGkrxDdrluEt9bxkeXqRgxGssXG/Wa+zdnNFY+3vrWksur/qrYhztyVZbi6HalHJnxVGC7PglWp0Ue+oS7GoJ/GVpWjWY/dlCli4ED7ssVfoLUedRR6w0wl0vTEso40cT0CHtimN5z5hr7BY/XGmvdP9dYKtHQHZMA2hjMra3sCCg38KCkJPfFkF5/yZzpOm2Am0LVLIuIrdWW+1rHA+LTK0VY6sOYxOaKmgSgf5RPBgPludUFZEOd/SaUkmGsGwKh83CPplv0iBU93mWlirsSzcsmxnU7xhmT+xzBvL1rEav8KJj8OlZcvgve1GqqJohg+0Rz+J8EHshnml0wJdJ3kRu3wb5q1x4c64AAeifEwqU02SRcqrUGXdKXBs4c6Io0sYztIUiladouwgbh1FkHrwcm5RfVO5sjWcONiVUQgl3ipj6JxljruM3SuOxnyji/6eLgrdD0BhLyVqqFPboT0HB/yYzuHJWWSMaJb5MiLqeUBU5nChxk3qTV/mQ5yLvtmiDrpNz9ZLlVccT1vg8+kFC8NzNGl4lP5L+ctOU8g2ktrEVPlZL6cV8E/h4i2k3KYfbxusiQYJeiONEBwcksB/xY3VwR5npSnoyVty15mS0RkymixAVyNZmvIPTg5ovBPFZJxifcl7wQwZtnTArcIlkh42mcnnwIfmcVPqb6FrDARxy+X+piYlT5w0itAKRhvTHe1adfY531Uvm+W+r5P7+d89XXSEEyHtnfoHuSHy0zPbTt9WmUPBRVUjuTP06K1uZ3NsNfeHNnQzmFdr3NqSgDsJJYrkg3RP3l1vUjF5LCI39PiWjhIBU28aMqjzlmwxW2ljQOt7g17w7QLJt0RzlN9SH+VuilJEac4fnuPFh541KxOVRPMqL39EGQTEYJBHf3y0N+medGsvIKZxYx84M6pYoLHWIzhZFjPaUDdeZlilDCA4MbChD9eBil68aspohtP3QQNZuev0djMg94a6OZOVD6hk7LJbHaqxi/q6JWiP/2jaOl3F0PJ7PS19jm0l0hdpPz6vUO+YGzlBuL6x6uxfASFULs50bxDRwmkRT1w49gRttpyCCkdz1zdkFMsqhpUFTr46EhDs2fXkvPmnxzRjhJRE8uFbiIgA8aCuHsPJBvFIyq0q+Eq5DZKRV5cv1Z8vIxsxn6WZPIkMUdEsSd1s1YpCB0+JhZRT7kA+JG76R6m94HfyRIk62KM7SAvU8/CW3DfbzEEqA1RUVnY6c6BmW42noQqwrQfkK50W6BbISeaYqpStsZaK3g6tDNWy0tWMY9wVuUrlggUeS+L9syoOxfKsbyh5HU8v6JvQUxawDIvJXiMr3I7+9EkEExlnxLfx9CLhKYFP1GUaIdFlgJrbQcReE6AS8j63TtyoAAS0ieoJ4UTKIqBTCSdxq1BChSTR23kLH8EUmGjkqmVf/a0LBQKIoJb+RpNZNtwolFMcpZHegnLEZuz1BAurmvT58ka+6Xp+qhP6nQBo3EtfDA3OW6ZnqQ05O3ioyaK1/DK27tUsLG6RY74hg+BI0T04uAE4Un2WDNHJAFb2fMNsaMJPNhtaKk5lLpQ0BIJsWn+ZdmPD82TQnRiryEvw8uhGkteSTVBjkLJ82ySR65xzpcZX0kHb0/+TjhJiQ/w7EKwOJRxiL3D6K7aYZTrPVv3hcZwUG/r/ZlhWo5/HS/Nvx499/FaKNWOURe3+YMlr6HWTbk/B5H2ldnMKZoiGvVAUtMFnItXJasR8M6TRogxlFhqwJsuEKcRquOExanANP4ddUQOb8kiFhUKPkAxaJj/TFsnUK0GScHYQtxBsIB0MBEDxugoPmLEmCdYzDSltpEmRpJrUed+ayOp9tmqS1duiVIHz5qrZrMEE6gZ39n/98+z2YNc81N/t8NjrZ9SggbYgCYEeRZItaCpk6kiNF2pWqzBG2SWK4S8ECSSUE5Gl1L10j8iCelNkxVx1LkXqlT2XhaAtq1HkFpyYclMoSh7qltJXj+nEZZITolORhMqUKG4IM7lnYRJSSlRCO5DT4N4hOMP5baSCG+zeIDcpKaUkXEugZBy2F2yNk84Nxyl9AR1HBDjaF5hqL+NELagAvKR0VIb5FjHGDYnNszyB+EdGuHfB4UudJR0FLEIMHxvKJOAe404hVGkqr5yDIrvCRRWQMCesjRF27qwjn1Zmkkbleepc677MAENPmdPvI1JyZOoKtlq6ALiaAx0RqLMFm6RtzPXV282JYpq4SsXgSAUHyC2ivBZslIjF4zGToVXkrmmrDlZ7CJNWFGrGVleIgnllsrpC7EsLmYXcSwk579qMA91U+WYAO1LXI7UxK+tHCPjfKJmXjPqluk6oaFrJn0d7+UPf96n+4eG2Daq22hw3LlypFPP7BmjBrbxvCrCS/EvGKwVnepdESo6WnPTYBtduhrxtTgPOIcMLaR8l4oV5mHIrENI7V7g7h9UbPhhl1OiKKBvwwM06VBsyGRTJntl9Wq14vXUVovmF89RdKu9OyUrDX2/cPiBqahoWKZt5VtuKnAX40dLQerlNENdxv/dMbtCw5EnT0sLVySq8U8FwsdoN1iW3bhZenN3tyEnFnqhWTL8lkhPXK6LNbp5CwlNmSnOZU9cegGVFiQhezWVUK4bV+PTYIllZBukscELHylbX85uqbr0LaME6WySwvi8YKFejWhrlymJmw1ckq9cSU/HlUV6oMU6+mv1vLjKziJtl90rVNamsm3td4TxZ82TXZDqm8O9ovtbgfLNqDHk7n40IG7hQzcLi9Dnnx3J18tPUiWZFZqmfE4xt/Zpnspo0cxNuKbcYWDeng4LbpSw5n6V5sxUawmg3fwmYYeg4WZaSemXftlrJdFJjGUaztVKZT0lPv2fBsGx6yjsGNkWmDmNXMI6MQktxR9yrw2zNgLiOEVklnwtel00a27Qmdzvagr7Qx1vRmcogfUojV/MdSPtq5mV+2eMhSKIAbZojGLNq7pecnqqT0qdEGZUMAa+39HJUpMEBhpE/czUzps3oOVs6JBPCLwLPyR8EnDJXVRPpFJLXI5PBxXyY4qXyxqaiVlW8y68njuqIGqlNUdW0av3pwgsJwj3KN3O2fMTqJFZIc0UqYjy/FPXmy6U3lVrlwGJaFSN8bxyxROQnvpukSja9srk2liYm2dqVwMweT6mnfe5kwIeJ29R2PZv+rHBODhTsQwoiWR/ElnK+XkBZigUaKxpHMto8WvXKmvS1GVfsrPbJJG/5OJzWWoyPbupXaX1jHCXYjwDO9yeXo5h6UYBCLc5HV+wwu8RYEkC4c2rhCkT4PLKkjMGu3SawJqbM1bH4R9Gwz+HJd83yiqHeYIJjFWoySPf0sZNOpG8YN3SlMEUC9fA0xRm5GtFmsv10wpRrpcC49ZOFapdoskRSBoOHZ/Rf7Wr1LRW6UbcSz2Q+z2a6Fo3dqYJntYBrIblX/7buhjvECb3QJO+b4HK/8SxUOAPJqacE0LNZSj8jLBaOalxyRLtaV5bXf14AxDzyE45ECpQgyBy4+40WXAplLm5h4JQI1GWiORjQKyWwYq/1QC5tCfX5zgp8GzYKurP9BoIs5UCRsQz9eTK2novK+txffU/X7NnntNhP1fuIBRfQCotY7cduRRm4VWClyNOoVsvTB3PD2QxACS25jpDnwrXYsf9go+Kei5WWPbZ9fV2tJBPt8s+eXVyxz1hgiHKj/jzrg+xPPgzniahIJYKlAZYbAiwNodfaf2oiGgEDwxLwvPzk6fnjpx//8fnjp/cPv3z+16cfNsogwPmhVrtAVrrIH66UH19RKgu9ICFE4e2SrD9PRX4Lnjw3VM5+cFDthlFKQRZ7ujLgJwgyrTPNqEZ7epTh1jIoO6k3Y+rGmF594vcec680VYIw+U+xqzbCpCJHsk5Upc3D1EIf14uzVPGjt8hp9mkgwJSWXz0knGg0T1QSl1YyhXa6V/RHEi9tKuBXKB2u5Pq8XTACOFA9D+Ru4Qod+FtNb2ZbxuHwfKf7p0cUFS3lrotaMY4ID8ky3mYlSZzDb6dl9J5hbzYxGNktLHber7OZnGWQo4LkrBO4Pb8w6VL87t1P3//pO35Z9/1/AAAA//8DADsBTbWXJwAA
)=====";
