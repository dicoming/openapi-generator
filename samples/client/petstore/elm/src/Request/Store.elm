{-
   OpenAPI Petstore
   This is a sample server Petstore server. For this sample, you can use the api key `special-key` to test the authorization filters.

   OpenAPI spec version: 1.0.0

   NOTE: This file is auto generated by the openapi-generator.
   https://github.com/openapitools/openapi-generator.git
   Do not edit this file manually.
-}


module Request.Store exposing (deleteOrder, getInventory, getOrderById, placeOrder)

import Data.Order_ as Order_ exposing (Order_)
import Dict
import Http
import Json.Decode as Decode


basePath : String
basePath =
    "http://petstore.swagger.io/v2"


{-| For valid response try integer IDs with value < 1000. Anything above 1000 or nonintegers will generate API errors
-}
deleteOrder : String -> Http.Request ()
deleteOrder orderId =
    { method = "DELETE"
    , url = basePath ++ "/store/order/" ++ orderId
    , headers = []
    , body = Http.emptyBody
    , expect = Http.expectStringResponse (\_ -> Ok ())
    , timeout = Just 30000
    , withCredentials = False
    }
        |> Http.request


{-| Returns a map of status codes to quantities
-}
getInventory : Http.Request (Dict.Dict String Int)
getInventory =
    { method = "GET"
    , url = basePath ++ "/store/inventory"
    , headers = []
    , body = Http.emptyBody
    , expect = Http.expectJson (Decode.dict Decode.int)
    , timeout = Just 30000
    , withCredentials = False
    }
        |> Http.request


{-| For valid response try integer IDs with value <= 5 or > 10. Other values will generated exceptions
-}
getOrderById : Int -> Http.Request Order_
getOrderById orderId =
    { method = "GET"
    , url = basePath ++ "/store/order/" ++ String.fromInt orderId
    , headers = []
    , body = Http.emptyBody
    , expect = Http.expectJson Order_.decoder
    , timeout = Just 30000
    , withCredentials = False
    }
        |> Http.request


placeOrder : Order_ -> Http.Request Order_
placeOrder model =
    { method = "POST"
    , url = basePath ++ "/store/order"
    , headers = []
    , body = Http.jsonBody <| Order_.encoder model
    , expect = Http.expectJson Order_.decoder
    , timeout = Just 30000
    , withCredentials = False
    }
        |> Http.request
