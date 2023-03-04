from escpos.printer import Usb
import TikTokLive
from TikTokLive import TikTokLiveClient
from TikTokLive.types.events import CommentEvent, ConnectEvent, GiftEvent, ShareEvent, LikeEvent, FollowEvent, \
    ViewerCountUpdateEvent

vendor_id = 0x0000  # You have to put the vendor id here
product_id = 0x0000  # You have to put the product id here
video_id = "@hixra_asmr"  # user id of the live video (Should starts from @)

# p = Usb(vendor_id, product_id)
client: TikTokLiveClient = TikTokLiveClient(
    unique_id=video_id, **(
        {
            "enable_extended_gift_info": True,
        }
    )
)


@client.on("connect")
async def on_connect(event: ConnectEvent):
    print("Connected")

#
# @client.on("comment")
# async def on_connect(event: CommentEvent):
#     # event.user.uniqueId => To print user id of the commentor
#     p.text(f"{event.user.nickname} commented on the video saying {event.comment}\n")
#     # print(f"{event.user.nickname} commented on the video saying {event.comment}\n")
#
#
# @client.on("gift")
# async def on_gift(event: GiftEvent):
#     # print(f"{event.user.nickname} sent a {event.gift.giftId}\n")
#     p.text(f"{event.user.nickname} sent a {event.gift.giftId}\n")
#
#
# @client.on("follow")
# async def on_follow(event: FollowEvent):
#     # print(f"{event.user.nickname} has started following you.\n")
#     p.text(f"{event.user.nickname} has started following you.\n")
#
#
# @client.on("like")
# async def on_like(event: LikeEvent):
#     p.text(f"{event.user.nickname} liked the video\n")
#     # print(f"{event.user.nickname} liked the video\n")
#
#
# @client.on("share")
# async def on_share(event: ShareEvent):
#     p.text(f"{event.user.nickname} shared the video\n")
#     # print(f"{event.user.nickname} shared the video\n")
#

if __name__ == '__main__':
    client.run()
